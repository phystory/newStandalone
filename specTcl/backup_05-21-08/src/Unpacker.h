/*************************************************************************** 
   COMPACT SpecTcl . BCS Standalone version for experiments 03034 & 05028
   Eventprocessor --> UNPACKER
   
   J.Pereira. Last version 8/29/2005
***************************************************************************/


#ifndef __BDECAYUNPACKER_H
#define __BDECAYUNPACKER_H

#ifndef __EVENTPROCESSOR_H
#include <EventProcessor.h>
#endif

#ifndef __TRANSLATORPOINTER_H
#include <TranslatorPointer.h>
#endif

#ifndef __TCLANALYZER_H
#include <TCLAnalyzer.h>
#endif

class CBDecayUnpacker : public  CEventProcessor
{
 public: 
  virtual Bool_t operator()(const Address_t pEvent,
			    CEvent&         rEvent,
			    CAnalyzer&      rAnalyzer,
			    CBufferDecoder& rDecoder);
  
 protected:
  void UnpackPacket(TranslatorPointer<UShort_t> p,
		    CEvent& rEvent);

  void UnpackPacketNERO(TranslatorPointer<UShort_t> p,
		    CEvent& rEvent);
};

#endif






