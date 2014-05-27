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

#ifndef __NEROSEGMENT_H
#define __NEROSEGMENT_H
#endif

#include <config.h>
#include <stdint.h>
#include <CEventSegment.h>
#include <CCompoundEventSegment.h>
#include <CEventPacket.h>

#ifndef __VC32WIENNERVC_H
#include <wienercamac.h> //Include Wienner CAMAC controller
#endif

#ifndef __CAENCARD_H
#include <CAENcard.h>  //Necessary for readout of CAEN VME modules 
#include <CAENcard_767.h>
#endif

#ifndef __CAENIO_H //Necessary for readout of CAEN V262 Event-register
#include <CaenIO.h>
#endif


#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

class NEROSegment : public CEventSegment
{
private:
  CAENcard* m_pVMEADC09;
  CAENcard* m_pVMEADC10;
  CAENcard_767* m_pVMETDC02;
  CAENcard* m_pVMEQDC12;    //QDC for readout of scintillators
  CCaenIO* m_pIOREGISTER;
  bool haveEvent();
  
public:
  virtual void initialize();
  virtual void clear();
  virtual size_t read(void* pBuffer, size_t maxwords);
};



