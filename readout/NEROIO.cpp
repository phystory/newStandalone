/*************************************************************************** 
   Readout program for NERO
   using Ring DAQ of NSCL DAQ 10.2-106
   Program includes:
    - Starting from a scratch Skeleton.h/cpp files
    - 1 Wienner VC32 CAMAC Controller (NERO)
    - VME Crate (number 1)
    - CAMAC Crate (number 2)

   08/25/2014 - First version created by Tony Ahn.
***************************************************************************/


#include <config.h>

#include "NEROIO.h"
#include <CaenIO.h>  //Necessary for readout of CAEN IO modules 

#define CAENTIMEOUT 100

///* Declare functions to initialize PicoSystems 16-ch. shaper/CFD modules
//   (Marc-Jan van Goethem) */
int initwushapers_nero();
int initwucfds_nero();

/* Declare initialization variables */
int Readout_NERO;

//Constructor
NEROIO::NEROIO(uint32_t base, int crate) :
    m_pIOREGISTER(new CCaenIO(base, crate))
{
}

//Destructor
NEROIO::~NEROIO()
{
}

void NEROIO::initialize()
{

  std::cout << "Initializing VME/CAMAC controllers" << std::endl;
    ///* Initialize Branch and CAMAC Crates */
    branchinit(0);
    crateinit(0,1); 

  std::cout << "Initializing CAMAC devices (shapers)" << std::endl;
    /* Initialize PicoSystems (aka Wash. U.) shaper/CFD's */
    //cout << "Setting gains and thresholds FOR PicoSytem MODULES " << endl;
    initwushapers_nero();
  std::cout << "Initializing CAMAC devices (CFDs)" << std::endl;
    initwucfds_nero();
    
  std::cout << "Initializing NERO IO register" << std::endl;
    /* Initialize CAEN V262 I/O Register */
    m_pIOREGISTER -> ClearAll();
}



void NEROIO::clear()
{ 
    m_pIOREGISTER->ClearAll(); /* Clear CAEN V262 I/O*/
}

size_t
NEROIO::read(void* pBuffer, size_t maxwords)
{

  int NeroTimeout=0;
  int Nerodata=0;
     

  for (int i=0; i<CAENTIMEOUT; i++) {
    Nerodata = m_pIOREGISTER -> ReadInput(1);
    if ( Nerodata != 0 ) { // Check that data is available 
   	break;
    }
  }
  m_pIOREGISTER->ClearLevel(1);                          //next 3 lines for cosmic start and nero stop-setup
  m_pIOREGISTER->SetLevel(1);  // Send NIM out on ch.1
  m_pIOREGISTER->ClearLevel(1);
    
  NeroTimeout = m_pIOREGISTER -> ReadInput(2); //channel 2 shows time out has occured 
  for (int i=1; i<=500; i++) {
 	 if (NeroTimeout == 0) {
	    NeroTimeout = m_pIOREGISTER -> ReadInput(2);
	 }
	 else {
	  break;
	 }
  }
      
  return Nerodata;

}
