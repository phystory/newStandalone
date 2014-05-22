/*
		    GNU GENERAL PUBLIC LICENSE
		       Version 2, June 1991

 Copyright (C) 1989, 1991 Free Software Foundation, Inc.
                       59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.

 This file contains a test readout system. It derives from the CReadoutMain 
 class to setup our experiment specific requirements creates an instance of 
 it and lets the base classes do most of the work.
*/


static const char* Copyright = "(C) Copyright Michigan State University 2002,All rights reserved"; 


/*************************************************************************** 
   Readout program for NERO 
   Program includes:
    - Updated Production Readout Software (version nscldaq8.0/g++3.3)
    - All electronics moved to VME
    - 1 Wienner VC32 CAMAC Controllers (for DSSD, SSSD and NERO)
    - VME Crate (number 0)

   J.Pereira. Last version 8/25/2005
   J.Pereira. Last version 10/24/2005
***************************************************************************/

#include <config.h>

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

#include <CReadoutMain.h>
#include <CExperiment.h>
#include <CInterpreterStartup.h>
#include <CInterpreterCore.h>
#include <CRunVariableCommand.h>
#include <CRunVariable.h>
#include <CStateVariableCommand.h>
#include <CStateVariable.h>
#include <TCLInterpreter.h>
#include <CDAQTCLProcessor.h>
#include <CVMEScalerLRS1151.h>
#include <wienercamac.h>
#include "NEROScaler.h"
#include <CTraditionalEventSegment.h>
#include <CTraditionalScalerReadout.h>
#include <CEventSegment.h>

#ifndef __BDecaySEGMENT_H
#define __BDecaySEGMENT_H
#endif
#ifndef __NEROSEGMENT_H
#include "NEROSegment.h"
#define __NEROSEGMENT_H
#endif



/* Define location base address of scalers */
/* Each module address needs 0xFFFFFF memory space */
#define BASEVMESCAL01 0x37000000 // NERO
#define BASEVMESCAL02 0x38000000 // NERO

/* Define the size, in words, of the largest possible physics event */
#define EVENT_MAXWORDS 1000


/*!
    Sample implementation of an experiment specific1
   tailoring of the production readout software.
*/

class CMyExperiment : public CReadoutMain
{
public:
   // Constructors and other canonical operations:

   CMyExperiment() {
   }
   virtual ~CMyExperiment() {
   }
   // Copy construction, assignment and comparison 
   // make no sense and are therefore disallowed:
private:
   CMyExperiment(const CMyExperiment& rhs);
   CMyExperiment& operator=(const CMyExperiment& rhs);
   int            operator==(const CMyExperiment& rhs);
   int            operator!=(const CMyExperiment& rhs);
public:
   // The member functions below allow us to override/extend base
   // class behavior for experiment specific stuff.
   
protected:
   virtual void SetupReadout(CExperiment& rExperiment);
   virtual void SetupScalers(CExperiment& rExperiment);

public:
   virtual void SetupRunVariables(CExperiment& rExperiment,
				  CInterpreterStartup& rStartup,
				  CInterpreterCore&    rCore);
   virtual void SetupStateVariables(CExperiment& rExperiment,
				  CInterpreterStartup& rStartup,
				  CInterpreterCore&    rCore);
   virtual void AddUserCommands(CExperiment& rExperiment,
				  CInterpreterStartup& rStartup,
				  CInterpreterCore&    rCore);
   
};

// The system relies on a globally accessible instsance of a CReadoutMain 
// derived object called MyApp so here it is:

CMyExperiment MyApp;

/*!
     In SetupReadout, you are expected to add Event segments to your 
     experiment.   Event segments read out logical sections of your 
     experiment.  The following types of event segments are available for your
     use:
       -    Simple event segments:  These are derived from the abstract base
              class CEventSegment, and are intended to readout a coherent piece
              of an experiment.
      -  Compatibility mode segments: These are objects of type
          CTraditionalEventSegment  they provide all the callouts to code
          that lives in an old-style skeleton.cpp file.  You will need to modify
          the skeleton makefile to add the oldstyle skeleton.cpp to the build.
          There can be only one CTraditionalEventSegment in the system due
           to function naming.
      -  Compound segments:  These are objects of type CCompoundEventSegment
          They consist of an ordered list of event segments of any type 
         (including, if you like other compound event segments).
   
       \param rExperiment - CExperiment& - A reference to the experiment object
       that runs the readout.  You will normally be making calls to 
       CExperiment::AddEventSegment to register your own event segments in the 
       experiment readout
*/
void CMyExperiment::SetupReadout(CExperiment& rExperiment)
{
  CReadoutMain::SetupReadout(rExperiment);
  //  rExperiment.EstablishTrigger(new CCAENV977Trigger(0xdddd0000));   
  //  rExperiment.EstablishBusy(new CCAENV977Status(0xdddd0000));   

  // Insert your code below this comment.
  //     CCompoundEventSegment* p = new CCompoundEventSegment;
  // p->AddSegment(new BDecaySegment);
  //  p->AddSegment(new NEROSegment);
  rExperiment.AddEventSegment(new NEROSegment); //Main-Segment included

}
/*!
    This function allows you to describe your scaler readout configuration.  
    This is done by 
    inserting scalers into the experiment object.   Scalers come in the 
    following flavors (all derived from CScaler) 
    - CCAMACScalerLRS2551  - CAMAC LeCroy model 2551 12 channel scalers.
    - CCAMACScalerLRS4434  - CAMAC LeCroy model 4434 32 channel scalers.
    - CVMEScalerCAENV830   - VME CAEN model V830 32 channel scalers.
    - CVMEScalerLRS1151    - VME LeCroy model 1151  scalers.
    - CScalerBank          - A collection of scalers sequentially read out.

   \param rExperiment - CExperiment& reference to the experiment object.
	    Normally  you will call CExperiment::AddScalerModule to add
	    scaler modules to the readout.
*/
void CMyExperiment::SetupScalers(CExperiment& rExperiment)
{
  CReadoutMain::SetupScalers(rExperiment);

   // Insert your code below this comment.

   // For test,setup an LRS 1151 at 0x200c00

  //  CScaler* pScaler = new CVMEScalerLRS1151(0xc00200);
  //  rExperiment.AddScalerModule(pScaler);

   /*Seven SIS3820 scaler objects will be defined 
     at different base adresses */
   rExperiment.AddScalerModule(new MainScaler(BASEVMESCAL01,0));
   rExperiment.AddScalerModule(new MainScaler(BASEVMESCAL02,0));
    
}
/*!
   In this function create and define any run variables you need. 
   A run variable is a TCL Variable whose value is logged to the
   event stream.   Run variables are always modifiable.

   If, for example, you have a thermocouple that is monitoring
   the temperature of a temperature senstive detector, you could
   create a RunVariable, monitor the temperature periodically
   and update the RunVariable.  See CRunVariable and
   CRunVariableCommand  Run variables can also be 
   create at the command line using the runvar command.

   \param rExperiment - CExperiment& the experiment object.
   \param rStartup   - CInterpreterStartup& the interpreter startup
                                            object.
    \param rCore  - CInterpreterCore& the core TCL interpreter
	 add on functionality.  Normally you will obtain the run
	 variable command object and do CRunVariableCommand::Create
	 calls to add your run variables.

   \note The base class creates key run variables.  It is therefore 
   very important to be sure the base class version of this function is
   called.
*/
void CMyExperiment::SetupRunVariables(CExperiment& rExperiment,
				  CInterpreterStartup& rStartup,
				  CInterpreterCore&   rCore)
{
  CReadoutMain::SetupRunVariables(rExperiment, rStartup, rCore);
  
  CRunVariableCommand& rCommand(*(rCore.getRunVariables()));
  
  // Add your code below this commet.rCommand is a reference to the run variable
  // commands object.
}
/*
   This function allows you to create run state variables.  Run state
   variables are TCL variables that are write locked during a run.  Their
   values are logged to run state variable buffers at run state transitions.

   An example of a run state variable is the run number; created by the
   base class.  An example of run variables you might like to create are
   fixed run conditions, such as beam species, energy, target species,
   trigger conditions etc.

   The Tcl command statevar can also be used to create list and delete
   state variables.

   \param rExperiment - CExperiment& the experiment object.
   \param rStartup   - CInterpreterStartup& the interpreter startup
                                            object.
    \param rCore  - CInterpreterCore& the core TCL interpreter
	 add on functionality.  Normally you will obtain the 
	 state variable command object and do CStateVariableCommand::Create
	 calls to add your run variables.

   \note The base class creates key run variables.  It is therefore 
   very important to be sure the base class version of this function is
   called.
*/
void
CMyExperiment::SetupStateVariables(CExperiment& rExperiment,
				   CInterpreterStartup& rStartup,
				   CInterpreterCore&    rCore)
{
   CReadoutMain::SetupStateVariables(rExperiment, rStartup, rCore);
   
   CStateVariableCommand& rCommand(*(rCore.getStateVariables()));
   
   // Insert your code below this comment.  Note that rCommand is the 
   // state variable command object.

}
/*!
  Add user written commands in this function.  User written commands
  should be objects derived from CDAQTCLProcessor  This will ensure that
  command execution will be properly synchronized to the rest of the application

   \param rExperiment - CExperiment& the experiment object.
   \param rStartup    - CInterpreterStartup& the interpreter startup object.  
                        Normally you will use this object
		        to locate the interpreter on which your commands
		        will be registered.
   \param rCore       - CInterpreterCore& the core TCL interpreter add on      
                        functionality. 

   \note The base class creates key command extensions (e.g. begin) it is
   important that the base class version of this function be called.

*/
void
CMyExperiment::AddUserCommands(CExperiment& rExperiment, 
				   CInterpreterStartup& rStartup,
				   CInterpreterCore&    rCore)
{
   CReadoutMain::AddUserCommands(rExperiment, rStartup, rCore);
   
   CTCLInterpreter& rInterp(rStartup.Interp());
   
   // Add your command definitions after this comment.  rInterp
   // is a reference to the interpreter.
}
void* gpTCLApplication;