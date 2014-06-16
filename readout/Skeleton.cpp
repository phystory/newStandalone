/*
    This software is Copyright by the Board of Trustees of Michigan
    State University (c) Copyright 2005.

    You may use this software under the terms of the GNU public license
    (GPL).  The terms of this license are described at:

     http://www.gnu.org/licenses/gpl.txt

     Author:
             Ron Fox
	     NSCL
	     Michigan State University
	     East Lansing, MI 48824-1321
*/

/*
  Description of the setup (26 January 2006):
  -----------------------------------------------------

  CAMAC NERO:
  Branch 1, crate 2 (NERO):
   1: DD002 dataway display
   2: Pico Systems 16-ch. shaper NERO Quadr A
   3: Pico Systems 16-ch. discriminator (double-wide with slot 2)
   4: Pico Systems 16-ch. shaper NERO Quadr B
   5: Pico Systems 16-ch. discriminator (double-wide with slot 4)
   6: Pico Systems 16-ch. shaper NERO Quadr C
   7: Pico Systems 16-ch. discriminator (double-wide with slot 6)
   8: Pico Systems 16-ch. shaper NERO Quadr D
   9: Pico Systems 16-ch. discriminator (double-wide with slot 8)
  10: EMPTY 
  12: EMPTY 
  13: EMPTY 
  14: EMPTY 
  15: EMPTY 
  16: EMPTY 
  17: EMPTY 
  18: EMPTY 
  19: EMPTY 
  20: EMPTY 
  21: EMPTY 
  22: EMPTY 
  23: EMPTY 
  24: Wienner CC32 highway controller
  25: Wienner CC32 highway controller (double-wide with slot 24)

  VME NERO:
  Branch 0, crate 1 (ADC and TDC readout):
   1: SBC/Bit3 interface
   2: SIS3820 32-ch. Scaler -- QUAD A & B
   3: SIS3820 32-ch. Scaler -- QUAD C & C
   4: EMPTY
   5: EMPTY
   6: CAEN V767 VME 64-ch  TDC -- QUAD A, B, C, D
   7: EMPTY 
   8: EMPTY 
   9: CAEN V785 VME 32-ch. ADC -- QUAD A & B
  10: CAEN V785 VME 32-ch. ADC -- QUAD C & D
  11: EMPTY
  12: EMPTY
  13: EMPTY
  14: CAEN V792 VME 32-ch. QDC -- Cosmic Ray Shield Scintillators CRS
  15: EMPTY
  16: EMPTY
  17: EMPTY 
  18: EMPTY 
  19: EMPTY 
  20: EMPTY 
  21: Wienner VC32 VME-CAMAC controller

*/

#include <config.h>
#include <Skeleton.h>
#include <CExperiment.h>
#include <CEventPacket.h>
#include <TCLInterpreter.h>
#include <CTimedTrigger.h>
#include <CCAENV262Trigger.h>
#include <CCAENV262Busy.h>

/* Define location of VME ADCs */
#define VMEADC09_N 9  /* NERO Quad A & B */
#define VMEADC10_N 10 /* NERO Quad C & D */

/*Define location of VME TDC */
#define VMETDC02_N 20 /* NERO TDC */

/*Define location of VME QDC */
#define VMEQDC12 0x0c000000   /*CRS QDC base address*/
#define VMEQDC12_N 12         /*slot number of QDC*/

/* Define base address of General Purpose IO Register (CaenIO.h)*/
#define BASEVMEIO 0x444400 


/* Define maximun readout time of VME modules*/
#define CAENTIMEOUT 100

/* Define VME Crate number */
#define VMEDEFAULTBASE 0
#define CRATENUM1 0

/* INCLUDE FILES */
/* The following include files were copied from the traditional Readout Software */
#include <string>
#include <stdlib.h>
#include <iostream>

/* Short circuit run time evaluation of constant BCNAF's */
#ifdef __unix__
#include <camac.h>
#else
#if CPU == IRONICS
#undef CAMBAS
#define CAMBAS(b)	0xFA800000
#endif

#if CPU == MICROPROJECT
#undef CAMBAS
#define CAMBAS(b)	0xFE800000
#endif
#endif

const std::string sNEROPacket="NEROPacket";
const std::string sNEROVME="NERO VME-CAMAC packet";
const std::string sPacketVersion="1.0";

/*
/*
** This file is a skeleton for the production readout software for
** NSCLDAQ 10.0 and later.  The programmatic interface
** to NSCLDAQ 10.0 at the application level is a 'close match' to that
** of earlier versions.  The software itself is a complete re-write so
** some incompatibilities may exist.  If you find an incompatibility,
** please post it at daqbugs.nscl.msu.edu so that it can be documented,
** and addressed.  Note that this does not necessarily mean that
** the incompatibility will be 'fixed'.
**
**   ------------------------------------------------------------
**
** How to use this skeleton:
**
**  This skeleton is the 'application' class for the production readout software.
**  The application class has several member functions you can override
**  and implement to perform user specific initialization.
**  These are:
**    SetupRunVariables   - Creates an initial set of run variables.
**    SetupStateVariables - Creates an initial set of state variables.
**    SetupReadout        - Sets up the software's trigger and its response to 
**                          that trigger.
**    SetupScalers        - Sets up the response to the scaler trigger and, if desired,
**                          modifies the scaler trigger from a periodic trigger controlled
**                          by the 'frequency' Tcl variable to something else.
**
** For more information about how to tailor this skeleton, see
** the comments in front of each member function.
**
*/

////////////////////////////////////////////////////////////////////////////////////////

/*
** Application frameworks require an 'entry point' object instance.  This
** is created below:
*/

CTCLApplication* gpTCLApplication = new Skeleton;

////////////////////////////////////////////////////////////////////////////////////////

/*!
  Setup the Readout This function must define the trigger as well as
  the response of the program to triggers.  A trigger is an object that
  describes when an event happens.  Triggers are objects derived from
  CEventTrigger
 
  \note  This function is incompatible with the pre 10.0 software in that
         for the 10.0 software, there was a default trigger that did useful stuff.
	 The default trigger for this version is a NULL trigger (a trigger that
	 never happens.  You _must_ create a trigger object and register it with the
	 experiment object via its EstablishTrigger member funti n else you'll never
	 get any events.

   The following are trigger classes you can use:
   - CNullTrigger - never fires. This is the default.
   - CTimedTrigger - Really intended for scaler triggers, but maybe there's an application
                     you can think of for a periodic event trigger.
   - CTestTrigger  - Always true. That's intended for my use, but you're welcome to use it
                     if you want a really high event rate.
   - CV262Trigger  - Uses the CAEN V262 as a trigger module.
   - CV977Trigger  - Uses the CAEN V977 as a trigger module.

   \param pExperiment - Pointer to the experiment object.

*/

void
Skeleton::SetupReadout(CExperiment* pExperiment)
{
  CReadoutMain::SetupReadout(pExperiment);

  // Establish your trigger here by creating a trigger object
  // and establishing it.
  pExperiment->EstablishTrigger(new CCAENV262Trigger(0x444400,0));
  pExperiment->EstablishBusy(new CCAENV262Busy(0x444400,0));

  // Create and add your event segments here, by creating them and invoking CExperiment's 
  m_pVMEADC09 = new NEROADC(VMEDEFAULTBASE, VMEADC09_N, CRATENUM1);
  //m_pVMEADC10 = new NEROADC(VMEDEFAULTBASE, VMEADC10_N, CRATENUM1);
  //m_pVMETDC02 = new NEROTDC(VMEDEFAULTBASE, VMETDC02_N, CRATENUM1);
  //m_pVMEQDC12 = new NEROQDC(VMEQDC12, VMEQDC12_N, CRATENUM1);    //QDC for readout of scintillators
  m_pIOREGISTER = new NEROIO(BASEVMEIO, CRATENUM1);
  // AddEventSegment
  m_NEROPacket = new CCompoundEventSegment;
  m_NEROPacket->AddEventSegment(m_pVMEADC09);
  //m_NEROPacket->AddEventSegment(m_pVMEADC10);
  //m_NEROPacket->AddEventSegment(m_pVMETDC02);
  //m_NEROPacket->AddEventSegment(m_pVMEQDC12);
  m_NEROPacket->AddEventSegment(m_pIOREGISTER);

  pExperiment->AddEventSegment(new CEventPacket(*m_NEROPacket,
											0xff01, sNEROPacket,sNEROVME, sPacketVersion));
  
}

/*!
  Very likely you will want some scalers read out.  This is done by
  creating scalers and adding them to the CExperiment object's
  list of scalers via a call to that object's AddScalerModule.

  By default, the scalers are read periodically every few seconds.  The interval
  between scaler readouts is defined by the Tcl variable frequency.

  You may replace this default trigger by creating a CEventTrigger derived object
  and passing it to the experiment's setScalerTrigger member function.

  \param pExperiment - Pointer to the experiment object.
*/
void
Skeleton::SetupScalers(CExperiment* pExperiment) 
{
  CReadoutMain::SetupScalers(pExperiment);	// Establishes the default scaler trigger.

  // Sample: Set up a timed trigger at 2 second intervals.

  timespec t;
  t.tv_sec  = 2;
  t.tv_nsec = 0;
  CTimedTrigger* pTrigger = new CTimedTrigger(t);
  pExperiment->setScalerTrigger(pTrigger);

  // Create and add your scaler modules here.
  //pExperiment->AddScalerModule(new MainScaler(BASEVMESCAL01,0));
  //pExperiment->AddScalerModule(new MainScaler(BASEVMESCAL02,0));


}
/*!
   Add new Tcl Commands here.  See the CTCLObjectProcessor class.  You can create new
   command by deriving a subclass from this abstract base class.  The base class
   will automatically register itself with the interpreter.  If you have some
   procedural commands you registered with Tcl_CreateCommand or Tcl_CreateObjCommand, 
   you can obtain the raw interpreter (Tcl_Interp*) of a CTCLInterpreter by calling
   its getInterp() member.

   \param pInterp - Pointer to the CTCLInterpreter object that encapsulates the
                    Tcl_Interp* of our main interpreter.

*/

void
Skeleton::addCommands(CTCLInterpreter* pInterp)
{
  CReadoutMain::addCommands(pInterp); // Add standard commands.
}

/*!
  Setup run variables:  A run variable is a Tcl variable whose value is periodically
  written to to the output event stream.  Run variables are intended to monitor things
  that can change in the middle of a run.  One use of a run variable is to
  monitor control system values.  A helper process can watch a set of control system
  variables, and issue set commands to the production readout program via its
  Tcl server component.  Those run variables then get logged to the event stream.

  Note that the base class may create run variables so see the comments in the function
  body about where to add code:

  See also:

     SetupStateVariables

     \param pInterp - pointer to the TCL interpreter.
*/

void
Skeleton::SetupRunVariables(CTCLInterpreter* pInterp)
{
  // Base class will create the standard commands like begin,end,pause,resume
  // runvar/statevar.

  CReadoutMain::SetupRunVariables(pInterp);

  // Add any run variable definitions below.

}

/*!
  Setup state variables: A state variable is a Tcl variable whose value is logged 
  whenever the run transitions to active.  While the run is not halted,
  state variables are write protected.  State variables are intended to 
  log a property of the run.  Examples of state variables created by the
  production readout framework are run and title which hold the run number,
  and the title.

  Note that the base class may create state variables so see the comments in the function
  body about where to add code:

  See also

  SetupRunVariables

  \param pInterp - Pointer to the tcl interpreter.
 
*/
void
Skeleton::SetupStateVariables(CTCLInterpreter* pInterp)
{
  CReadoutMain::SetupStateVariables(pInterp);

  // Add any state variable definitions below:

  
}
