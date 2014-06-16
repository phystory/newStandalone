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

#include "NEROADC.h"
#include <CAENcard.h>  //Necessary for readout of CAEN VME modules 


/* Declare initialization variables */
int ADC_thresh=10;

//Constructor
NEROADC::NEROADC(uint32_t base, uint8_t id, int crate)  :
    //m_pCard(new CAENcard(id, 0, false, base))
    m_pCard(new CAENcard(id, 0, true, base))
{
}

//Destructor
NEROADC::~NEROADC()
{
}

void NEROADC::initialize()
{

  std::cout << "Initializing NEROADC" << std::endl;

        m_pCard->reset();
        sleep(2);
        m_pCard->setThreshold(-1, ADC_thresh);// Threshold into all channels 
        m_pCard->clearData();
        m_pCard->resetEventCounter();
        m_pCard->discardUnderThresholdData();
        m_pCard->keepOverflowData();
}



void NEROADC::clear()
{ 
    m_pCard->clearData(); /* Clear CAEN V785 ADC1 */
}

size_t
NEROADC::read(void* pBuffer, size_t maxwords)
{
    if (maxwords < 34*2 ) {
      throw
        std::string("NEROADC - insufficient buffers space for worst cae event");
    }

    for (int i=0;i<30;i++) {
      if(haveEvent()) break;
    }

    int n = (m_pCard->readEvent(pBuffer))/sizeof(uint16_t);

    return n;
}
 
bool
NEROADC::haveEvent()
{
    return m_pCard->dataPresent();
}

