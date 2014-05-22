/*      File:  bdecayVariables.h
        mod 13nov01 by pfm 
        mod 18nov02 by pfm for 01006
	mod 20apr04 by BET for 03005
	Variable definitions for the betadecay
	The root variable name is bdecayv
	Author: D. Bazin
	Date: July 2001
	Mod 1Sep05 J.Pereira
*/

#ifndef __TREEVARIABLE_H
#include <TreeParameter.h>
#endif

//#ifndef __BDECAYVARIABLES_H
//#define __BDECAYVARIABLES_H
//#ifndef __NEROVARIABLES_H
//#define __NEROVARIABLES_H


// NERO //

struct chcalibrator
{
	CTreeVariable& offset;
	CTreeVariable& gain;
};

/* The NERO setup */

struct detectorcalibrator
{
	struct chcalibrator ecalib_quadA[16];
        struct chcalibrator ecalib_quadB[16];
        struct chcalibrator ecalib_quadC[16];
        struct chcalibrator ecalib_quadD[16];
        struct chcalibrator tcalib_quadA[16];
        struct chcalibrator tcalib_quadB[16];
        struct chcalibrator tcalib_quadC[16];
        struct chcalibrator tcalib_quadD[16];
};

/* following the declarations, this is the actual construction
    of the variable tree structure defined in bdecayV.h */

extern struct detectorcalibrator nerov;

//#endif
