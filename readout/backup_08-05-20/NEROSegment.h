/*************************************************************************** 
   Readout program for NERO
   Experiments 03034 & 05028
   Program includes:
    - Updated Production Readout Software (version nscldaq8.0/g++3.3)
    - 1 Wienner VC32 CAMAC Controller (NERO)
    - VME Crate (number 1)
    - CAMAC Crate (number 2)

   J.Pereira. Last version 8/25/2005
   J.Pereira. Last version 10/24/2005
***************************************************************************/

#ifndef __NEROSEGMENT_H
#define __NEROSEGMENT_H
#endif

#include <config.h>
#include <spectrodaq.h>
#include <CEventSegment.h>
#include <CDocumentedPacket.h>

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
  CDocumentedPacket m_NEROPacket;  
  CAENcard* m_pVMEADC09;
  CAENcard* m_pVMEADC10;
  CAENcard_767* m_pVMETDC02;
  CCaenIO* m_pIOREGISTER;
  
public:
  NEROSegment();
  virtual void Initialize();
  virtual void Clear();
  virtual unsigned int MaxSize();
  virtual DAQWordBufferPtr& Read(DAQWordBufferPtr& rBuf);
};



