/*************************************************************************** 
   COMPACT SpecTcl . BCS Standalone version for experiments 03034 & 05028

   J.Pereira. Last version 8/29/2005
***************************************************************************/

#ifndef __BETASPECTCL_H  //Required for current class

#define __BETASPECTCL_H
                               //Required for base classes
#ifndef __TCLGRAMMERAPP_H      //CTclGrammerApp
#include "TclGrammerApp.h"
#endif
 

class CBDecaySpecTcl  : public CTclGrammerApp        
{
 public:
  /* Default constructor alternative to compiler provided default constructor */
  CBDecaySpecTcl ();
  /* Destructor - Delete any pointer data members that used new in constructors. 
     Destructor should be virtual if and only if class contains at least one virtual 
     function. Objects destroyed in the reverse order of the construction order */  
  ~ CBDecaySpecTcl ( );  
 private:
  //Copy Constructor 
  CBDecaySpecTcl (const CBDecaySpecTcl& aCBDecaySpecTcl );
  
  //Operator= Assignment Operator 
  CBDecaySpecTcl& operator= (const CBDecaySpecTcl& aCBDecaySpecTcl);
  
  //Operator== Equality Operator 
  int operator == (const CBDecaySpecTcl& aCBDecaySpecTcl) const;
  
 public:
  
  // Class operations:
  
 public:
  
  virtual   void BindTCLVariables (CTCLInterpreter& rInterp)   ; // 
  virtual   void SourceLimitScripts (CTCLInterpreter& rInterpreter)   ; // 
  virtual   void SetLimits ()   ; // 
  virtual   void CreateHistogrammer ()   ; // 
  virtual   void SelectDisplayer (UInt_t nDisplaySize, 
				  CHistogrammer& rHistogrammer)   ; // 
  virtual   void SetupTestDataSource ()   ; // 
  virtual   void CreateAnalyzer (CEventSink* pSink)   ; // 
  virtual   void SelectDecoder (CAnalyzer& rAnalyzer)   ; // 
  virtual   void CreateAnalysisPipeline (CAnalyzer& rAnalyzer)   ; // 
  virtual   void AddCommands (CTCLInterpreter& rInterp)   ; // 
  virtual   void SetupRunControl ()   ; // 
  virtual   void SourceFunctionalScripts (CTCLInterpreter& rInterp)   ; // 
  virtual   int operator() ()   ; // 

};

#endif
