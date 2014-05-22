/*************************************************************************** 
   COMPACT SpecTcl . BCS Standalone version for experiments 03034 & 05028
   Eventprocessor --> THRESHOLD
   
   J.Pereira. Last version 8/31/2005
   mod FM & LK 11/01/2005
   mod JPC 11/10/2005 (11:00aM)
***************************************************************************/

#include <config.h>
#include <EventProcessor.h>
#include <TCLAnalyzer.h>
#include <Event.h> 
#include <math.h> 

#include "Parameters.h"
#include "Variables.h"

#include "Threshold.h"

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

Bool_t
CBDecayThreshold::operator()(const Address_t pEvent,
			     CEvent&         rEvent,
			     CAnalyzer&      rAnalyzer,
			     CBufferDecoder& rDecoder)
{
  int i,j;
  long    isum,dsum,sumhi,sumlo,dsumtotal,isumtotal; /* DSSD and SSSD energy sums */
  long    isumch,dsumch,sumhich,sumloch; /* DSSD and SSSD weighted sums */
  long    icent,dcent,centa,centb; /* DSSD and SSSD centroids */
  long    imax,dmax,maxhi,maxlo,dmaxtotal,imaxtotal; /* DSSD and SSSD maximum energies */
  long    imaxch,dmaxch,maxhich,maxloch; /* DSSD and SSSD energy peaks */
  long    imult,dmult,multhi,multlo; /* DSSD and SSSD multiplicities */
  long    segatotal,gmult,xmatrix,ymatrix; /* SEGA totals */

  /* Set calorimeter hit mask to zero */
  long    calhitmask=0;


  //cout << "Begin BCS Threshold" <<endl;
  //printf("Begin BCS Threshold\n");


  /* Set total energies to zero before starting */
  dsumtotal = 0; /* Total decay energy based on energy sums within each detector */
  dmaxtotal = 0; /* Total decay energy based on maximum energy observed within each detector */

  isumtotal = 0; /* Total implant energy including DSSD front energy sum */
  imaxtotal = 0; /* Total implant energy including maximum energy observed in DSSD front */

  /* set hit flags to zero before starting */
  
  bdecayv.hit.pin00 = 0;
  bdecayv.hit.pin01 = 0;
  bdecayv.hit.pin02 = 0;
  bdecayv.hit.pin03 = 0;
  bdecayv.hit.pin04 = 0;
  bdecayv.hit.n3scint = 0;
  bdecayv.hit.ge = 0;
  bdecayv.hit.fronthi = 0;
  bdecayv.hit.frontlo = 0;
  bdecayv.hit.backhi = 0;
  bdecayv.hit.backlo = 0;
  bdecayv.hit.sssd1hi = 0;
  bdecayv.hit.sssd1lo = 0;
  bdecayv.hit.sega = 0;

  /* set SeGA matrix to zero */

  bdecay.segatotal.xmatrix = -1;
  bdecay.segatotal.ymatrix = -1;

  /* set front and  back positions, multiplicities and energies */
  bdecay.front.dmax = 0;
  bdecay.front.dmaxch = 0;
  bdecay.front.dsum = 0;
  bdecay.front.dmult = 0;
  bdecay.front.dcent = 300;
  bdecay.front.imax = 0;
  bdecay.front.imaxch = 0;
  bdecay.front.isum = 0;
  bdecay.front.imult = 0;
  bdecay.front.icent = 300;
  bdecay.back.dmax = 0;
  bdecay.back.dmaxch = 0;
  bdecay.back.dsum = 0;
  bdecay.back.dmult = 0;
  bdecay.back.dcent = 300;
  bdecay.back.imax = 0;
  bdecay.back.imaxch = 0;
  bdecay.back.isum = 0;
  bdecay.back.imult = 0;
  bdecay.back.icent = 300;

  /* PINs, Ge and scintillators */

  if (((word)bdecay.bit.betabit1 & 0xFFF) != 0 )
    {
      /* Pin00 */
      //if ( rEvent[bdecay.pin00.ecal.getId()].isValid() ) {
      //if ((bdecay.pin00.ecal) > (bdecayv.pin00.thresh)) 
      //	  {
      //	    bdecayv.hit.pin00 = 1;
      //	    isumtotal += (long)bdecay.pin00.ecal; /* Increment total implant energies */
      //	    imaxtotal += (long)bdecay.pin00.ecal;
      //	  }
      //}

      /* Pin01 */
      if ( rEvent[bdecay.pin01.ecal.getId()].isValid() ) {
	if ((bdecay.pin01.ecal) > (bdecayv.pin01.thresh)) 
	  {
	    bdecayv.hit.pin01 = 1;
	    isumtotal += (long)bdecay.pin01.ecal; /* Increment total implant energies */
	    imaxtotal += (long)bdecay.pin01.ecal;
	  }
      }
      /* Pin02 */
      if ( rEvent[bdecay.pin02.ecal.getId()].isValid() ) {
	if ((bdecay.pin02.ecal) > (bdecayv.pin02.thresh))
	  {
	    bdecayv.hit.pin02 = 1;
	    isumtotal += (long)bdecay.pin02.ecal; /* Increment total implant energies */
	    imaxtotal += (long)bdecay.pin02.ecal;
	  }
      }
      /* Pin03 */
      if ( rEvent[bdecay.pin03.ecal.getId()].isValid() ) {
	if ((bdecay.pin03.ecal) > (bdecayv.pin03.thresh))
	  {
	    bdecayv.hit.pin03 = 1;
	    isumtotal += (long)bdecay.pin03.ecal; /* Increment total decay energies */
	    imaxtotal += (long)bdecay.pin03.ecal;
	  }
      }
      /* Pin04 */
      if ( rEvent[bdecay.pin04.ecal.getId()].isValid() ) {
	if ((bdecay.pin04.ecal) > (bdecayv.pin04.thresh))
	  {
	    bdecayv.hit.pin04 = 1;
	    isumtotal += (long)bdecay.pin04.ecal; /* Increment total decay energies */
	    imaxtotal += (long)bdecay.pin04.ecal;
	  }
      }
      /* N3 beamline scintillator */
      if ( rEvent[bdecay.n3scint.ecal.getId()].isValid() ) {
	if ((bdecay.n3scint.ecal) > (bdecayv.n3scint.thresh)) bdecayv.hit.n3scint = 1;
      }
      /* Thick beta scintillator */
      if ( rEvent[bdecay.ge.ecal.getId()].isValid() ) {
	if ((bdecay.ge.ecal) > (bdecayv.ge.thresh)) bdecayv.hit.ge = 1;
      }
    }
  
  /* DSSD and SSSD */

  isum = 0;
  dsum = 0;
  isumch = 0;
  dsumch = 0;
  imax = 0;
  dmax = 0;
  imaxch = 0;
  dmaxch = 0;
  imult = 0;
  dmult = 0;

  /* Strips 1-16 Front high and low */
  
  if (((word)bdecay.bit.betabit1&0x1) != 0) 
    {
      for (i=1;i<17;i++)
	{
	  /* Decay ADC */
	  if ( rEvent[bdecay.front.hiecal[i].getId()].isValid() ) {
	    if ((bdecay.front.hiecal[i] >= bdecayv.fthresh.hithresh[i]) && (bdecay.front.hiecal[i] <= bdecayv.fthresh.duld[i]))
	      {
		bdecayv.hit.fronthi = 1;
		dmult++; /* Increment multiplicity */
		dsum += long(bdecay.front.hiecal[i]); /* Increment energy sum */
		dsumch += j*long(bdecay.front.hiecal[i]); /* Increment weighted sum */
		if (bdecay.front.hiecal[i]>dmax) 
		  {
		    dmax = long(bdecay.front.hiecal[i]); /* Record maximum energy */
		    dmaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	  /* Implant ADC */
	  if ( rEvent[bdecay.front.loecal[i].getId()].isValid() ) {
	    if ( (bdecay.front.loecal[i] >= bdecayv.fthresh.lothresh[i]) )
	      {
		bdecayv.hit.frontlo = 1;
		imult++; /* Increment multiplicity */
		isum += long(bdecay.front.loecal[i]); /* Increment energy sum */
		isumch += j*long(bdecay.front.loecal[i]); /* Increment weighted sum */
		if (bdecay.front.loecal[i]>imax) 
		  {
		    imax = long(bdecay.front.loecal[i]); /* Record maximum energy */
		    imaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	}
    }
  
  /* Strips 17-32 Front High and low*/
  
  if (((word)bdecay.bit.betabit1&0x2) != 0) 
    {
      for (i=17;i<33;i++)
	{
	  /* Decay ADC */
	  if ( rEvent[bdecay.front.hiecal[i].getId()].isValid() ) {
	    if ((bdecay.front.hiecal[i] >= bdecayv.fthresh.hithresh[i]) && (bdecay.front.hiecal[i] <= bdecayv.fthresh.duld[i]))
	      {
		bdecayv.hit.fronthi = 1;
		dmult++; /* Increment multiplicity */
		dsum += long(bdecay.front.hiecal[i]); /* Increment energy sum */
		dsumch += j*long(bdecay.front.hiecal[i]); /* Increment weighted sum */
		if (bdecay.front.hiecal[i]>dmax) 
		  {
		    dmax = long(bdecay.front.hiecal[i]); /* Record maximum energy */
		    dmaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	  /* Implant ADC */
	  if ( rEvent[bdecay.front.loecal[i].getId()].isValid() ) {
	    if ( (bdecay.front.loecal[i] >= bdecayv.fthresh.lothresh[i]) )
	      {
		bdecayv.hit.frontlo = 1;
		imult++; /* Increment multiplicity */
		isum += long(bdecay.front.loecal[i]); /* Increment energy sum */
		isumch += j*long(bdecay.front.loecal[i]); /* Increment weighted sum */
		if (bdecay.front.loecal[i]>imax) 
		  {
		    imax = long(bdecay.front.loecal[i]); /* Record maximum energy */
		    imaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	}
    }

  /* Strips 33-40 Front High and low*/
  
  if (((word)bdecay.bit.betabit1&0x4) != 0) 
    {
      for (i=33;i<41;i++)
	{
	  /* Decay ADC */
	  if ( rEvent[bdecay.front.hiecal[i].getId()].isValid() ) {
	    if ((bdecay.front.hiecal[i] >= bdecayv.fthresh.hithresh[i]) && (bdecay.front.hiecal[i] <= bdecayv.fthresh.duld[i]))
	      {
		bdecayv.hit.fronthi = 1;
		dmult++; /* Increment multiplicity */
		dsum += long(bdecay.front.hiecal[i]); /* Increment energy sum */
		dsumch += j*long(bdecay.front.hiecal[i]); /* Increment weighted sum */
		if (bdecay.front.hiecal[i]>dmax) 
		  {
		    dmax = long(bdecay.front.hiecal[i]); /* Record maximum energy */
		    dmaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	  /* Implant ADC */
	  if ( rEvent[bdecay.front.loecal[i].getId()].isValid() ) {
	    if ( (bdecay.front.loecal[i] >= bdecayv.fthresh.lothresh[i]) )
	      {
		bdecayv.hit.frontlo = 1;
		imult++; /* Increment multiplicity */
		isum += long(bdecay.front.loecal[i]); /* Increment energy sum */
		isumch += j*long(bdecay.front.loecal[i]); /* Increment weighted sum */
		if (bdecay.front.loecal[i]>imax) 
		  {
		    imax = long(bdecay.front.loecal[i]); /* Record maximum energy */
		    imaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	}
    }

   if(bdecayv.hit.fronthi != 0) 
    {
      calhitmask += 1; /* Add bit 0 to calorimeter hit mask */
      bdecay.front.dmult=dmult;
      bdecay.front.dmax=dmax;
      bdecay.front.dmaxch=dmaxch;
      bdecay.front.dsum=dsum;
      if (dsum != 0) 
	{
	  bdecay.front.dcent = long(dsumch/dsum); /* Decay ADC centroid */
	} 
      else 
	{
	  bdecay.front.dcent = 100;
	}
      dsumtotal += dsum; /* Start accumulating total energy based on 
			  energy sums within each detector */
      dmaxtotal += dmax; /* Start accumulating total energy based on 
			  maximum energy observed in each detector */
    }

  if(bdecayv.hit.frontlo != 0) 
    {
      bdecay.front.imult=imult;
      bdecay.front.imax=imax;
      bdecay.front.imaxch=imaxch;
      bdecay.front.isum=isum;
      if (isum != 0) 
	{
	  bdecay.front.icent = long(isumch/isum); /* Implant ADC centroid */
	} 
      else 
	{
	  bdecay.front.icent = 100;
	}
      isumtotal += isum; /* Increment total implant energies */
      imaxtotal += imax;
    }
  
  isum = 0;
  dsum = 0;
  isumch = 0;
  dsumch = 0;
  imax = 0;
  dmax = 0;
  imaxch = 0;
  dmaxch = 0;
  imult = 0;
  dmult = 0;

  /* Strips 1-16 Back high and low */
  
  if (((word)bdecay.bit.betabit1&0x8) != 0) 
    {
      for (i=1;i<17;i++)
	{
	  /* Decay ADC */
	  if ( rEvent[bdecay.back.hiecal[i].getId()].isValid() ) {
	    if ((bdecay.back.hiecal[i] >= bdecayv.bthresh.hithresh[i]) && (bdecay.back.hiecal[i] <= bdecayv.bthresh.duld[i]))
	      {
		bdecayv.hit.backhi = 1;
		dmult++; /* Increment multiplicity */
		dsum += long(bdecay.back.hiecal[i]); /* Increment energy sum */
		dsumch += j*long(bdecay.back.hiecal[i]); /* Increment weighted sum */
		if (bdecay.back.hiecal[i]>dmax) 
		  {
		    dmax = long(bdecay.back.hiecal[i]); /* Record maximum energy */
		    dmaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	  /* Implant ADC */
	  if ( rEvent[bdecay.back.loecal[i].getId()].isValid() ) {
	    if ( (bdecay.back.loecal[i] >= bdecayv.bthresh.lothresh[i]) )
	      {
		bdecayv.hit.backlo = 1;
		imult++; /* Increment multiplicity */
		isum += long(bdecay.back.loecal[i]); /* Increment energy sum */
		isumch += j*long(bdecay.back.loecal[i]); /* Increment weighted sum */
		if (bdecay.back.loecal[i]>imax) 
		  {
		    imax = long(bdecay.back.loecal[i]); /* Record maximum energy */
		    imaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	}
    }
  
  /* Strips 17-32 Back High and low*/
  
  if (((word)bdecay.bit.betabit1&0x10) != 0) 
    {
      for (i=17;i<33;i++)
	{
	  /* Decay ADC */
	  if ( rEvent[bdecay.back.hiecal[i].getId()].isValid() ) {
	    if ((bdecay.back.hiecal[i] >= bdecayv.bthresh.hithresh[i]) && (bdecay.back.hiecal[i] <= bdecayv.bthresh.duld[i]))
	      {
		bdecayv.hit.backhi = 1;
		dmult++; /* Increment multiplicity */
		dsum += long(bdecay.back.hiecal[i]); /* Increment energy sum */
		dsumch += j*long(bdecay.back.hiecal[i]); /* Increment weighted sum */
		if (bdecay.back.hiecal[i]>dmax) 
		  {
		    dmax = long(bdecay.back.hiecal[i]); /* Record maximum energy */
		    dmaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	  /* Implant ADC */
	  if ( rEvent[bdecay.back.loecal[i].getId()].isValid() ) {
	    if ( (bdecay.back.loecal[i] >= bdecayv.bthresh.lothresh[i]) )
	      {
		bdecayv.hit.backlo = 1;
		imult++; /* Increment multiplicity */
		isum += long(bdecay.back.loecal[i]); /* Increment energy sum */
		isumch += j*long(bdecay.back.loecal[i]); /* Increment weighted sum */
		if (bdecay.back.loecal[i]>imax) 
		  {
		    imax = long(bdecay.back.loecal[i]); /* Record maximum energy */
		    imaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	}
    }
  /* Strips 33-40 Back High and low*/
  
  if (((word)bdecay.bit.betabit1&0x20) != 0) 
    {
      for (i=33;i<41;i++)
	{
	  /* Decay ADC */
	  if ( rEvent[bdecay.back.hiecal[i].getId()].isValid() ) {
	    if ((bdecay.back.hiecal[i] >= bdecayv.bthresh.hithresh[i]) && (bdecay.back.hiecal[i] <= bdecayv.bthresh.duld[i]))
	      {
		bdecayv.hit.backhi = 1;
		dmult++; /* Increment multiplicity */
		dsum += long(bdecay.back.hiecal[i]); /* Increment energy sum */
		dsumch += j*long(bdecay.back.hiecal[i]); /* Increment weighted sum */
		if (bdecay.back.hiecal[i]>dmax) 
		  {
		    dmax = long(bdecay.back.hiecal[i]); /* Record maximum energy */
		    dmaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	  /* Implant ADC */
	  if ( rEvent[bdecay.back.loecal[i].getId()].isValid() ) {
	    if ( (bdecay.back.loecal[i] >= bdecayv.bthresh.lothresh[i]) )
	      {
		bdecayv.hit.backlo = 1;
		imult++; /* Increment multiplicity */
		isum += long(bdecay.back.loecal[i]); /* Increment energy sum */
		isumch += j*long(bdecay.back.loecal[i]); /* Increment weighted sum */
		if (bdecay.back.loecal[i]>imax) 
		  {
		    imax = long(bdecay.back.loecal[i]); /* Record maximum energy */
		    imaxch = i; /* Record location of maximum energy */
		  }
	      }
	  }
	}
    }
  
  if(bdecayv.hit.backhi != 0) 
    {
      calhitmask += 2; /* Add bit 0 to calorimeter hit mask */
      bdecay.back.dmult=dmult;
      bdecay.back.dmax=dmax;
      bdecay.back.dmaxch=dmaxch;
      bdecay.back.dsum=dsum;
      if (dsum != 0) 
	{
	  bdecay.back.dcent = long(dsumch/dsum); /* Decay ADC centroid */
	} 
      else 
	{
	  bdecay.back.dcent = 100;
	}
      dsumtotal += dsum; /* Start accumulating total energy based on 
			  energy sums within each detector */
      dmaxtotal += dmax; /* Start accumulating total energy based on 
			  maximum energy observed in each detector */
    }

  if(bdecayv.hit.backlo != 0) 
    {
      bdecay.back.imult=imult;
      bdecay.back.imax=imax;
      bdecay.back.imaxch=imaxch;
      bdecay.back.isum=isum;
      if (isum != 0) 
	{
	  bdecay.back.icent = long(isumch/isum); /* Implant ADC centroid */
	} 
      else 
	{
	  bdecay.back.icent = 100;
	}
      isumtotal += isum; /* Increment total implant energies */
      imaxtotal += imax;
    }

 sumhi = 0;
 sumlo = 0;
 sumhich = 0;
 sumloch = 0;
 maxhi = 0;
 maxlo = 0;
 maxhich = 0;
 maxloch = 0;
 multhi = 0;
 multlo = 0;
 

/* Strips 1-16 SSSD1 high and low */
  
  if (((word)bdecay.bit.betabit1&0x40) != 0) 
    {
      for (i=1; i<17; i++) 
	{
	  /* SSSD1 High */
	  if ( rEvent[bdecay.sssd1.hiecal[i].getId()].isValid() ) {
	    if ((bdecay.sssd1.hiecal[i] >= bdecayv.sssd1.hithresh[i]) && (bdecay.sssd1.hiecal[i] <= bdecayv.sssd1.uld[i]))
	      {
		bdecayv.hit.sssd1hi = 1;
		multhi++; /* Increment multiplicity */
		sumhi += long(bdecay.sssd1.hiecal[i]); /* Increment energy sum */
		sumhich += i*long(bdecay.sssd1.hiecal[i]); /* Increment weighted sum */
		if (bdecay.sssd1.hiecal[i]>maxhi) 
		  {
		    maxhi = long(bdecay.sssd1.hiecal[i]); /* Record maximum energy */
		    maxhich = i; /* Record location of maximum energy */
		  }
	      }
	  }
	  /* SSSD1 Low */
	  if ( rEvent[bdecay.back.loecal[i].getId()].isValid() ) {
	    if ((bdecay.sssd1.loecal[i] >= bdecayv.sssd1.lothresh[i]))
	      {
		bdecayv.hit.sssd1lo = 1;
		multlo++; /* Increment multiplicity */
		sumlo += long(bdecay.sssd1.loecal[i]); /* Increment energy sum */
		sumloch += i*long(bdecay.sssd1.loecal[i]); /* Increment weighted sum */
		if (bdecay.sssd1.loecal[i]>maxlo) 
		  {
		    maxlo = long(bdecay.sssd1.loecal[i]); /* Record maximum energy */
		    maxloch = i; /* Record location of maximum energy */
		  }
	      }
	    
	  }
	}
    }
  
   if(bdecayv.hit.sssd1hi != 0) 
    { 
      calhitmask += 4; /* Add bit 2 to calorimeter hit mask */
      bdecay.sssd1.himult = multhi;
      bdecay.sssd1.himax = maxhi;
      bdecay.sssd1.himaxch = maxhich;
      bdecay.sssd1.hisum = sumhi;
      if (sumhi != 0) 
	{
	  bdecay.sssd1.hicent = long(sumhich/sumhi); /* Calculate ADC centroid */
	} else {
	  bdecay.sssd1.hicent = 100;
	}
      dsumtotal += sumhi; /* Increment sum-based total energy */
      dmaxtotal += maxhi; /* Increment maximum-based total energy */
    }

    if(bdecayv.hit.sssd1lo != 0) 
    { 
      calhitmask += 8; /* Add bit 3 to calorimeter hit mask */
      bdecay.sssd1.lomult = multlo;
      bdecay.sssd1.lomax = maxlo;
      bdecay.sssd1.lomaxch = maxloch;
      bdecay.sssd1.losum = sumlo;
      if (sumlo != 0) 
	{
	  bdecay.sssd1.locent = long(sumloch/sumlo); /* Calculate ADC centroid */
	} else {
	  bdecay.sssd1.locent = 100;
	}
    }

  /* Implant and decay totals */

  bdecay.total.isum = isumtotal;
  bdecay.total.imax = imaxtotal;

  bdecay.total.dsum = dsumtotal;
  bdecay.total.dmax = dmaxtotal;

  bdecay.bit.calhitmask = calhitmask;


  /* SeGA detectors */

  segatotal = 0;
  gmult = 0;
  xmatrix = 0;
  ymatrix = 0;
  
  /* SEGA01 */
  
  if(((word)bdecay.bit.betabit1&0x2000) ||((word)bdecay.bit.betabit1&0x800)  != 0) {

    if (bdecay.sega.ecal[1] > bdecayv.sega.thresh[1])
      {
	bdecayv.hit.sega = 1;
	segatotal += UInt_t(bdecay.sega.ecal[1]);
	gmult++;
	if (gmult == 1)
	  {
	    xmatrix = UInt_t(bdecay.sega.ecal[1]);
	  }
	if (gmult == 2)
	  {
	    ymatrix = UInt_t(bdecay.sega.ecal[1]);
	  }
      }
  }

  /* SEGA02 */

  if(((word)bdecay.bit.betabit1&0x4000) ||((word)bdecay.bit.betabit1&0x800)  != 0) {
    
    if (bdecay.sega.ecal[2] > bdecayv.sega.thresh[2])
      {
	bdecayv.hit.sega = 1;
	segatotal += UInt_t(bdecay.sega.ecal[2]);
	gmult++;
	if (gmult == 1)
	  {
	    xmatrix = UInt_t(bdecay.sega.ecal[2]);
	  }
	if (gmult == 2)
	  {
	    ymatrix = UInt_t(bdecay.sega.ecal[2]);
	  }
      }
  }
    

  /* SEGA03 */

  if(((word)bdecay.bit.betabit1&0x8000) ||((word)bdecay.bit.betabit1&0x800)  != 0) {
    
    if (bdecay.sega.ecal[3] > bdecayv.sega.thresh[3])
      {
	bdecayv.hit.sega = 1;
	segatotal += UInt_t(bdecay.sega.ecal[3]);
	gmult++;
	if (gmult == 1)
	  {
	    xmatrix = UInt_t(bdecay.sega.ecal[3]);
	  }
	if (gmult == 2)
	  {
	    ymatrix = UInt_t(bdecay.sega.ecal[3]);
	  }
      }
  }

  //cout << "End BCS Threshold" <<endl;
  //printf("End BCS Threshold\n");



  /* End of event */
  return kfTRUE; /* kfFALSE would abort pipeline */
  
};

