/*************************************************************************** 
   COMPACT SpecTcl . BCS Standalone version for experiments 03034 & 05028
   Eventprocessor --> CORRELATOR
   
   J.Pereira. Last version 9/1/2005
***************************************************************************/

#ifndef __BDECAYCORRELATOR_H
#define __BDECAYCORRELATOR_H

#ifndef __EVENTPROCESSOR_H
#include <EventProcessor.h>
#endif

#ifndef __TRANSLATORPOINTER_H
#include <TranslatorPointer.h>
#endif

#ifndef __TCLANALYZER_H
#include <TCLAnalyzer.h>
#endif

class CBDecayCorrelator : public  CEventProcessor
{
public:
  virtual Bool_t operator()(const Address_t pEvent,
			    CEvent&         rEvent,
			    CAnalyzer&      rAnalyzer,
			    CBufferDecoder& rDecoder);

};

#endif
