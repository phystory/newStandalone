/*************************************************************************** 
   COMPACT SpecTcl . BCS Standalone version for experiments 03034 & 05028

   J.Pereira. Last version 8/29/2005
***************************************************************************/

#include <config.h>

#include <Event.h> 
#include <EventProcessor.h>
#include <TCLAnalyzer.h>
#include <vector>
#include <histotypes.h>
#include <string>
#include <stdio.h>
#include <Analyzer.h>
#include <TCLHistogrammer.h>
#include <Spectrum2DW.h>
#include <Spectrum1DW.h>
#include <Spectrum.h>
#include <SpectrumFactory.h>
#include <Parameter.h>

#include "SpecTcl.h"
#include "Unpacker.h"
//#include "Calibrator.h"
//#include "Threshold.h"
//#include "Correlator.h"
#include "Parameters.h"
#include "Variables.h"
#include "P.h"
#include "V.h"

#include <TreeParameter.h>

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif


// Create  unpacker (see Unpacker.cpp)
static CBDecayUnpacker UnpackBDecay;
// Create BDecay calibrator (see Calibrator.cpp)
//static CBDecayCalibrator CalibrateBDecay;
/* Create BDecay threshold (see Threshold.cpp) */
//static CBDecayThreshold ThresholdBDecay;
/* Create Bdecay correlator (see Correlator.cpp) */
//static CBDecayCorrelator CorrelatorBDecay;

/*  
    Function: 	
    void CreateAnalysisPipeline(CAnalyzer& rAnalyzer) 
    Operation Type:
    Override

    Purpose: 	
    Sets up an analysis pipeline.  This function is required and must
    be filled in by the SpecTcl user.  Pipeline elements are objects
    which are members of classes derived from the CEventProcessor
    class. They should be added to the Analyzer's event processing pipeline
    by calling RegisterEventProcessor (non virtual base class member).

*/

void 
CBDecaySpecTcl::CreateAnalysisPipeline(CAnalyzer& rAnalyzer)  
{ 
  RegisterEventProcessor(UnpackBDecay);
  //  RegisterEventProcessor(CalibrateBDecay);
  //  RegisterEventProcessor(ThresholdBDecay);
  //  RegisterEventProcessor(CorrelatorBDecay);
}  

// Constructors, destructors and other replacements for compiler cannonicals:
CBDecaySpecTcl::CBDecaySpecTcl ()
{   
} 

// Destructor:

CBDecaySpecTcl::~CBDecaySpecTcl ( )
{
} 


// Functions for class CBDecaySpecTcl

/*  
    Function: 	
    void BindTCLVariables(CTCLInterpreter& rInterp) 
    Operation Type:
    override
    
    Purpose: 	
    Add code to this function to bind any TCL variable to
    the SpecTcl interpreter.  Note that at this time,
    variables have not yet been necessarily created so you
    can do Set but not necessarily Get operations.
*/
void 
CBDecaySpecTcl::BindTCLVariables(CTCLInterpreter& rInterp)  
{ 
  CTclGrammerApp::BindTCLVariables(rInterp);
  CTreeVariable::BindVariables(rInterp);
}  

/*
  Function: 	
  void SourceLimitScripts(CTCLInterpreter& rInterpreter) 
  Operation Type:
  Override
  
  Purpose: 	
  Add code here to source additional variable setting
  scripts.  At this time the entire SpecTcl/Tk infrastructure
  is not yet set up.  Scripts run at this stage can only run
  basic Tcl/Tk commands, and not SpecTcl extensions.
  Typically, this might be used to set a bunch of initial values
  for variables which were bound in BindTCLVariables.
*/
void 
CBDecaySpecTcl::SourceLimitScripts(CTCLInterpreter& rInterpreter)  
{ 
  CTclGrammerApp::SourceLimitScripts(rInterpreter);
}  

/*
  Function: 	
  void SetLimits() 
  Operation Type:
  overide
  
  Purpose: 	
  
  Called after BindVariables and SourceLimitScripts.
  This function can be used to fetch values of bound Tcl
  variables which were modified/set by the limit scripts to
  update program default values. 
*/

void 
CBDecaySpecTcl::SetLimits()  
{ 
  CTclGrammerApp::SetLimits();
}  

/*
  Function: 	
  void CreateHistogrammer() 
  Operation Type:
  Override
  
  Purpose: 	
  Creates the histogramming data sink.  If you want to override
  this in general you probably won't make use of the actual
  base class function.  You might, however extend this by 
  defining a base set of parameters and histograms from within
  the program.
*/

void 
CBDecaySpecTcl::CreateHistogrammer()  
{ 
  CTclGrammerApp::CreateHistogrammer();
}  

/* 
   Function: 	
   void SelectDisplayer(UInt_t nDisplaySize, CHistogrammer& rHistogrammer) 
   Operation Type:
   Override.
   
   Purpose: 	
   Select a displayer object and link it to the
   histogrammer.  The default code will link Xamine
   to the displayer, and set up the Xamine event handler
   to deal with gate objects accepted by Xamine interaction.
*/

void 
CBDecaySpecTcl::SelectDisplayer(UInt_t nDisplaySize, CHistogrammer& rHistogrammer)  
{ CTclGrammerApp::SelectDisplayer(nDisplaySize, rHistogrammer);
}  


/* 
   Function: 	
   void SetupTestDataSource() 
   Operation Type:
   Override
   
   Purpose: 	
   Allows you to set up a test data source.  At
   present, SpecTcl must have a data source of some sort
   connected to it... The default test data source produces a 
   fixed length event where all parameters are selected from
   a gaussian distribution.  If you can figure out how to do it,
   you can setup your own data source... as long as you don't
   start analysis, the default one is harmless.
*/
void 
CBDecaySpecTcl::SetupTestDataSource()  
{ CTclGrammerApp::SetupTestDataSource();
}  

/* 
   Function: 	
   void CreateAnalyzer(CEventSink* pSink) 
   Operation Type:
   Override
   
   Purpose: 	
   Creates an analyzer.  The Analyzer is connected to the data
   source which supplies buffers.  Connected to the analyzer is a
   buffer decoder and an event unpacker.  The event unpacker is 
   the main experiment dependent chunk of code, not the analyzer.
   The analyzer constructed by the base class is a CTclAnalyzer instance.
   This is an analyzer which maintains statistics about itself in Tcl Variables.
*/

void 
CBDecaySpecTcl::CreateAnalyzer(CEventSink* pSink)  
{ CTclGrammerApp::CreateAnalyzer(pSink);
}  

/* 
   Function: 	
   void SelectDecoder(CAnalyzer& rAnalyzer) 
   Operation Type:
   Override
   
   Purpose: 	
   Selects a decoder and attaches it to the analyzer.
   A decoder is responsible for knowing the overall structure of
   a buffer produced by a data analysis system.  The default code
   constructs a CNSCLBufferDecoder object which knows the format
   of NSCL buffers.
*/

void 
CBDecaySpecTcl::SelectDecoder(CAnalyzer& rAnalyzer)  
{ 
  CTclGrammerApp::SelectDecoder(rAnalyzer);
}  

/* 
   Function: 	
   void AddCommands(CTCLInterpreter& rInterp) 
   Operation Type:
   Override

   Purpose: 	
   This function adds commands to extend Tcl/Tk/SpecTcl.
   The base class function registers the standard SpecTcl command
   packages.  Your commands can be registered at this point.
   Do not remove the sample code or the SpecTcl commands will
   not get registered.
*/

void 
CBDecaySpecTcl::AddCommands(CTCLInterpreter& rInterp)  
{ 
  CTclGrammerApp::AddCommands(rInterp);
}  

/* 
   Function: 	
   void SetupRunControl() 
   Operation Type:
   Override.
   
   Purpose: 	
   Sets up the Run control object.  The run control object
   is responsible for interacting with the underlying operating system
   and programming framework to route data from the data source to 
   the SpecTcl analyzer.  The base class object instantiates a 
   CTKRunControl object.  This object uses fd waiting within the 
   Tcl/TK event processing loop framework to dispatch buffers for
   processing as they become available.
*/

void 
CBDecaySpecTcl::SetupRunControl()  
{ 
  CTclGrammerApp::SetupRunControl();
}  

/* 
   Function: 	
   void SourceFunctionalScripts(CTCLInterpreter& rInterp) 
   Operation Type:
   Override
   
   Purpose: 	
   This function allows the user to source scripts
   which have access to the full Tcl/Tk/SpecTcl
   command set along with whatever extensions have been
   added by the user in AddCommands.  
*/

void 
CBDecaySpecTcl::SourceFunctionalScripts(CTCLInterpreter& rInterp)  
{ 
  CTclGrammerApp::SourceFunctionalScripts(rInterp);
}  

/* 
   Function: 	awesome
   int operator()() 
   Operation Type:
   Override.

   Purpose: 	
   Entered at Tcl/Tk initialization time (think of this
   as the entry point of the SpecTcl program).  The base
   class default  implementation calls the member functions
   of this class in an appropriate order.  It's possible for the user
   to extend this functionality by adding code to this function.
*/

int 
CBDecaySpecTcl::operator()()  
{ 
  return CTclGrammerApp::operator()();
}

CBDecaySpecTcl   myApp;
CTclGrammerApp& app(myApp);	 // Create an instance of me.
CTCLApplication* gpTCLApplication=&app;  // Findable by the Tcl/tk framework.
