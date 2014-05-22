/*************************************************************************** 
   COMPACT SpecTcl . BCS Standalone version for experiments 03034 & 05028
   Eventprocessor --> CORRELATOR
   
   J.Pereira. Last version 9/1/2005
***************************************************************************/
/*
  Correlation flags:
   4 - invalid implant pixel
   8 - invalid decay pixel
  12 - implant event
  16 - decay event 
  20 - unknown event
  24 - front, no back decay
  28 - back, no front decay
  32 - back-to-back implant
  36 - back-to-back decay
  40 - invalid implant time
  44 - invalid decay time
  48 - exceeded correlation time
  52 - long-lived implant rejection
  62 - reset correlation array 
*/

#include <config.h>
#include <EventProcessor.h>
#include <TCLAnalyzer.h>
#include <Event.h> 
#include <math.h> 

#include "Parameters.h"
#include "Variables.h"

#include "Correlator.h"
 
#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif


typedef struct 
{
  bool implanted;
  long time; /* Time of event, in 30.5 us clockticks */
  long de1;  /* dE from PIN01 */
  long de2; /* dE from PIN02 */
  long de3;  /* dE from PIN03 */
  long de4; /* dE from PIN04 */
  long isum; /* Total implant (kinetic) energy */
  long imax; /* Total implant (kinetic) energy */
  long tof;  /* Time of flight */
  long dt;   /* Time since last implant */
} IMPLANT;

typedef struct 
{
  long time; /* Time of event, in 30.5 us clock ticks */
  long de1;  /* dE from PIN01 */
  long de2; /* dE from PIN02 */
  long de3;  /* dE from PIN03 */
  long de4; /* dE from PIN04 */
  long isum; /* Total implant (kinetic) energy */
  long imax; /* Total implant (kinetic) energy */
  long tof;  /* Time of flight */
  long dt;   /* Time since last implant */
} DECAY;

IMPLANT implant[41][41]; /* implant data [x (back)][y (front)] */
DECAY decay[41][41];     /* correlated decay data */  

Bool_t
CBDecayCorrelator::operator()(const Address_t pEvent,
			      CEvent&         rEvent,
			      CAnalyzer&      rAnalyzer,
			      CBufferDecoder& rDecoder)
{
  int i,j;
  int condition = 0;
  int resetcheck = 0;
  int ibackch = 100;
  int ifrontch = 100;
  int dbackch =  100;
  int dfrontch = 100; 
 
  bool implant_event = false;
  bool decay_event = false;
  bool punchthrough = false;
  bool unknown_event = false;
  bool front_noback = false;
  bool back_nofront = false;

  //cout << "Start correlator " << endl;

  /* correlation array reset */
  /* need to set bdecayv.corr.reset.ne.0 at start of each run */

  //cout << "Begin BCS Correlator" <<endl;
  //printf("Begin BCS Correlator\n");

  if(bdecayv.corr.reset != 0) 
    {

      for(i=1; i<41; i++) 
	{
	  for( j=1; j<41; j++ )
	    {
	      implant[i][j].implanted = false;
	      implant[i][j].time = 0;
	      implant[i][j].de1 = 0;
	      implant[i][j].de2 = 0;
	      implant[i][j].de3 = 0;
	      implant[i][j].de4 = 0;
	      implant[i][j].isum = 0;
	      implant[i][j].imax = 0;
	      implant[i][j].tof = 0;
	      implant[i][j].dt = 0;
	      decay[i][j].time = 0;
	      decay[i][j].de1 = 0;
	      decay[i][j].de2 = 0;
	      decay[i][j].de3 = 0;
	      decay[i][j].de4 = 0;
	      decay[i][j].isum = 0;
	      decay[i][j].imax = 0;
	      decay[i][j].tof = 0;
	      decay[i][j].dt = 0;
	    }
	}

      bdecayv.corr.reset = 0;
    }  
  
  /* Implant/decay logic */
  
  /*
    The pixel location is defined by the front and back strips 
    showing the maximum implanted energy in each side of the detector.
    The strip array runs from 1 to 40; a correction to map from a
    0-39 to 1-40 scale is no longer necessary.  If there is no event
    data, imaxch and dmaxch are set to 100; there are channel checks
    to reject events with invalid positions (i.e. outside a 1-40 range).
    ACM, 2003/01/26
  */
     
  if((bdecayv.hit.pin01 != 0)&&(bdecayv.hit.frontlo != 0)&&		\
   (bdecayv.hit.backlo !=0)&&(bdecayv.hit.sssd1hi == 0)) implant_event = true;
  if((bdecayv.hit.pin01 == 0)&&(bdecayv.hit.fronthi !=0)&& \
     (bdecayv.hit.backhi != 0))                          decay_event = true;
  if((bdecayv.hit.pin01 != 0)&&(bdecayv.hit.frontlo != 0)&&		\
     (bdecayv.hit.backlo !=0)&&(bdecayv.hit.sssd1hi != 0)) punchthrough = true;
  if ((bdecayv.hit.fronthi != 0)&&(bdecayv.hit.backhi == 0)) front_noback = true;
  if ((bdecayv.hit.fronthi == 0)&&(bdecayv.hit.backhi != 0)) back_nofront = true; 

  bdecay.bit.corrmask = 0;

  if (implant_event)  
    {
      ifrontch=(int)bdecay.front.imaxch;  /* x and y are from implant um", 13)),
    *(new CTreeParameter("bdecay.corr.dimmax channel */
      ibackch=(int)bdecay.back.imaxch;

      if(ibackch>=1 && ibackch<=40 && ifrontch>=1 && ifrontch<=40)
	{
	  bdecay.bit.corrmask += 1; /* Real implant flag (bit-1) */
	  /* Check for existing implant in pixel */
	  if (implant[ibackch][ifrontch].implanted) 
	    {
	      bdecay.bit.corrmask += 2; /* Back-to-back implant flag (bit-2) */
	      if (implant[ibackch][ifrontch].time > bdecay.clock.current) bdecay.bit.corrmask += 4; /* Bad implant time flag (bit-3) */
	      implant[ibackch][ifrontch].dt = long(bdecay.clock.current - implant[ibackch][ifrontch].time);
	      /* Output time between implants in 10 ms units on 10-bit spectrum
		 with 16-bit parameter declaration */
	      bdecay.corr.dtimplant = long(implant[ibackch][ifrontch].dt*bdecayv.clock.calib);

	    } 
	  else 
	    {
	      implant[ibackch][ifrontch].implanted = true;
	    } 
	  
	  /* Update time */
	  implant[ibackch][ifrontch].time = bdecay.clock.current;
	  bdecay.corr.itime = (long)implant[ibackch][ifrontch].time;

	  /* Update dE from PIN1 */
	  if ( rEvent[bdecay.pid.de1.getId()].isValid() ) {
	    implant[ibackch][ifrontch].de1  = bdecay.pid.de1;
	    bdecay.corr.ide1  = (long)implant[ibackch][ifrontch].de1;
	  }
	  if ( rEvent[bdecay.pid.de2.getId()].isValid() ) {
	    implant[ibackch][ifrontch].de2 = bdecay.pid.de2;
	    bdecay.corr.ide2  = (long)implant[ibackch][ifrontch].de2;
	  }
	  if ( rEvent[bdecay.pid.de3.getId()].isValid() ) {
	    implant[ibackch][ifrontch].de3  = bdecay.pid.de3;
	    bdecay.corr.ide3  = (long)implant[ibackch][ifrontch].de3;
	  }
	  if ( rEvent[bdecay.pid.de4.getId()].isValid() ) {
	    implant[ibackch][ifrontch].de4 = bdecay.pid.de4;
	    bdecay.corr.ide4 = (long)implant[ibackch][ifrontch].de4;
	  }
	  if ( rEvent[bdecay.pid.isum.getId()].isValid() ) {
	    implant[ibackch][ifrontch].isum = bdecay.pid.isum;
	    bdecay.corr.iisum  = (long)implant[ibackch][ifrontch].isum;
	  }
	  if ( rEvent[bdecay.pid.imax.getId()].isValid() ) {
	    implant[ibackch][ifrontch].imax = bdecay.pid.imax;
	    bdecay.corr.iimax  = (long)implant[ibackch][ifrontch].imax;
	  }
	  if ( rEvent[bdecay.pid.i2ntof.getId()].isValid() ) {
	    implant[ibackch][ifrontch].tof = bdecay.pid.i2ntof;
	    bdecay.corr.itof  = (long)implant[ibackch][ifrontch].tof;
	  }
	}
      else
	{
	  bdecay.bit.corrmask += 8; /* invalid implant pixel (bit-4)*/
	}
    }

  else if (decay_event)
    {
      dfrontch=(int)bdecay.front.dmaxch;  /* x and y are from decay max channel */
      dbackch=(int)bdecay.back.dmaxch;

      if(dbackch>=1 && dbackch<=40 && dfrontch>=1 && dfrontch<=40) 
	{
	  bdecay.bit.corrmask += 16; /* Real decay flag (bit-5)*/

	  if (implant[dbackch][dfrontch].implanted) 
	    {
	      /* Check to see that clock is incrementing */
	      if (implant[dbackch][dfrontch].time > bdecay.clock.current) bdecay.bit.corrmask += 32; /* Bad decay time flag (bit-6)*/
	      /* Make sure time between back-to-back implants is long; if not, reject event */
	      if (((implant[dbackch][dfrontch].dt) >= bdecayv.corr.minimplant*bdecayv.clock.scale)||(implant[dbackch][dfrontch].dt==0))
		{
		  /* Do not process correlations that extend beyond a fixed time */
		  if ((bdecay.clock.current - implant[dbackch][dfrontch].time) < (bdecayv.clock.max*bdecayv.clock.scale)) 
		    {
		      decay[dbackch][dfrontch].time = bdecay.clock.current;
		      decay[dbackch][dfrontch].dt   = (long)(bdecay.clock.current - implant[dbackch][dfrontch].time);	
		      /* Output decay time in 10 ms units on 10-bit spectrum
			 with 16-bit parameter declaration */
		      bdecay.corr.dtimecal = (long)(decay[dbackch][dfrontch].dt*bdecayv.clock.calib);
		      bdecay.corr.dtime = (long)decay[dbackch][dfrontch].time;
		      decay[dbackch][dfrontch].de1  = implant[dbackch][dfrontch].de1;
		      decay[dbackch][dfrontch].de2  = implant[dbackch][dfrontch].de2;
		      decay[dbackch][dfrontch].de3  = implant[dbackch][dfrontch].de3;
		      decay[dbackch][dfrontch].de4 = implant[dbackch][dfrontch].de4;
		      decay[dbackch][dfrontch].isum = implant[dbackch][dfrontch].isum;
		      decay[dbackch][dfrontch].imax = implant[dbackch][dfrontch].imax;
		      decay[dbackch][dfrontch].tof  = implant[dbackch][dfrontch].tof;	
		      /* Output decay time in 10 ms units on 10-bit spectrum
			 with 16-bit parameter declaration */
		      bdecay.corr.dtimecal = (long)(decay[dbackch][dfrontch].dt*bdecayv.clock.calib);
		      bdecay.corr.dtime = (long)decay[dbackch][dfrontch].time;
		      bdecay.corr.dde1  = (long)decay[dbackch][dfrontch].de1;
		      bdecay.corr.dde2  = (long)decay[dbackch][dfrontch].de2;
		      bdecay.corr.dde3  = (long)decay[dbackch][dfrontch].de3;
		      bdecay.corr.dde4 = (long)decay[dbackch][dfrontch].de4;
		      bdecay.corr.disum = (long)decay[dbackch][dfrontch].isum;
		      bdecay.corr.dimax = (long)decay[dbackch][dfrontch].imax;
		      bdecay.corr.dtof  = (long)decay[dbackch][dfrontch].tof;
		    } 
		  else 
		    {
		      bdecay.bit.corrmask += 64;  /* Correlation time too long flag (bit-7)*/
		    }
		  //implant[dbackch][dfrontch].implanted = false;
		}  
	      else 
		{
		  bdecay.bit.corrmask += 128;  /* Time between implants too short flag (bit-8)*/
		}
	    } 
	  else 
	    { 
	      bdecay.bit.corrmask += 256;  /* Decay but no previous implant flag (bit-9) */
	    }
	}
      else 
	{
	  bdecay.bit.corrmask += 512 ; /* Invalid decay pixel (bit-10) */
	}
    }

  else if (punchthrough == true )
    {
      bdecay.bit.corrmask += 1024; /* punchthrough bit (bit-11) */ 
    }
  
  else
    {      
      bdecay.bit.corrmask += 2048; /* Unknown event flag (bit-12)*/
      if (front_noback == true) bdecay.bit.corrmask += 4096; /* fronthi but not backhi (bit-13)*/
      else if (back_nofront == true) bdecay.bit.corrmask +=  8192 /* not fronthi but backhi (bit=14) */;
    }
    
  
  /* End of user logic */

  //cout << "Begin BCS Correlator" <<endl;
  //printf("Begin BCS Correlator\n");

  
  return kfTRUE; /* kfFALSE would abort pipeline */  
  
};

