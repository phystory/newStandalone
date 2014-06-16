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

#include "NEROQDC.h"
#include <CAENcard.h>  //Necessary for readout of CAEN VME modules 


/* Declare initialization variables */
int QDC_thresh=0;

//Constructor
NEROQDC::NEROQDC(uint32_t base, uint8_t id, int crate)  :
    m_pCard(new CAENcard(id, 0, true, base))
{
}

//Destructor
NEROQDC::~NEROQDC()
{
}

void NEROQDC::initialize()
{

  std::cout << "Initializing NEROQDC" << std::endl;

        m_pCard->reset();
        sleep(2);
        m_pCard->setThreshold(-1, QDC_thresh);// Threshold into all channels 
        m_pCard->clearData();
        m_pCard->resetEventCounter();
	     m_pCard->setPedestalCurrent(60);
        m_pCard->discardUnderThresholdData();
        m_pCard->keepOverflowData();
}



void NEROQDC::clear()
{ 
    m_pCard->clearData(); /* Clear CAEN V785 QDC1 */
}

size_t
NEROQDC::read(void* pBuffer, size_t maxwords)
{
    if (maxwords < 34*2 ) {
      throw
        std::string("NEROQDC - insufficient buffers space for worst cae event");
    }

    for (int i=0;i<30;i++) {
      if(haveEvent()) break;
    }

    int n = (m_pCard->readEvent(pBuffer))/sizeof(uint16_t);

    return n;
}
 
bool
NEROQDC::haveEvent()
{
    return m_pCard->dataPresent();
}
