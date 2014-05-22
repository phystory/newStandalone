/*      File: bdecayParameters.h
	Parameter definitions for the beta-decay setup
	Author: Colin Morton
	Date: September 2001
        mod 15nov01 by pfm
	mod 20apr04 by BET for 03005:  added i2ntof to PID and TAC; added sega to TAC
	The root parameter name is bdecayP_standalone.h
	mod 1Sep05 by JPC for 03034 and 05028

*/





#ifndef __TREEPARAMETER_H
#include <TreeParameter.h>
#endif

#ifndef __BDECAYPARAMETERS_H
#define __BDECAYPARAMETERS_H


// NERO Parameters

/* Bit Registers */
struct bitregister
{
  CTreeParameter& quadAhitpattern;
  CTreeParameter& quadBhitpattern;
  CTreeParameter& quadChitpattern;
  CTreeParameter& quadDhitpattern;
  CTreeParameter& multiplicity;
  CTreeParameter& nodatamask;    
  CTreeParameter& timesum;  
};

/* defining base unit of counter */
struct counter
{
  CTreeParameter& energy;
  CTreeParameter& energymatch;
  CTreeParameter& time;
  CTreeParameter& timecal;
 };

/* The NERO set-up */

struct detector
{
  struct bitregister coincregister;
  struct counter quadrantA[16];
  struct counter quadrantB[16];
  struct counter quadrantC[16];
  struct counter quadrantD[16];
};

/* following the declarations, this is the actual construction
    of the parameter tree structure which is done in bdecayP.h */

extern struct detector nero;
#endif
