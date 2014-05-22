/*************************************************************************** 
   COMPACT SpecTcl . BCS Standalone version for experiments 03034 & 05028
   Eventprocessor --> THRESHOLD
   
   J.Pereira. Last version 8/31/2005
***************************************************************************/

#ifndef __BDECAYTHRESHOLD_H
#define __BDECAYTHRESHOLD_H

#ifndef __EVENTPROCESSOR_H
#include <EventProcessor.h>
#endif

#ifndef __TRANSLATORPOINTER_H
#include <TranslatorPointer.h>
#endif

#ifndef __TCLANALYZER_H
#include <TCLAnalyzer.h>
#endif

class CBDecayThreshold : public  CEventProcessor
{
public:
  virtual Bool_t operator()(const Address_t pEvent,
			    CEvent&         rEvent,
			    CAnalyzer&      rAnalyzer,
			    CBufferDecoder& rDecoder);

};

#endif
