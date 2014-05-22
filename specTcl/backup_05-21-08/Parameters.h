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

/* Bit registers */
struct bit
{
  CTreeParameter& betabit1;
  CTreeParameter& betabit2;
  CTreeParameter& nodatamask;
  CTreeParameter& calhitmask;
  CTreeParameter& corrmask;
};

/* Clock */
struct clock
{
  CTreeParameter& fast;
  CTreeParameter& slow;
  CTreeParameter& current;
  CTreeParameter& csis1;
  CTreeParameter& csis2;
  CTreeParameter& csiscurrent;
};

/* ADCs */
struct adc
{
  CTreeParameterArray& adc01;
  CTreeParameterArray& adc02;
  CTreeParameterArray& adc03;
  CTreeParameterArray& adc04;
  CTreeParameterArray& adc05;
  CTreeParameterArray& adc06;
  CTreeParameterArray& adc07;
  CTreeParameterArray& adc08;
};

/* TDCs */
struct tdc
{
  CTreeParameterArray& tdc01;
};

/* PIN */
struct pin
{
  CTreeParameter& energy;
  CTreeParameter& time;
  CTreeParameter& ecal;
};

/* Scintillator */
struct scint
{
  CTreeParameter& energy;
  CTreeParameter& time;
  CTreeParameter& ecal;
};

/* RF */
struct RF
{
  CTreeParameter& time;
};

/* Image 2 scintillator, south PMT */
struct i2sci
{
  CTreeParameter& time;
};

/* Ge crystal */
struct ger
{
  CTreeParameter& energy;
  CTreeParameter& time;
  CTreeParameter& ecal;
};

/* DSSD */
struct dssd
{
  CTreeParameterArray& hienergy;
  CTreeParameterArray& loenergy;
  CTreeParameterArray& hiecal;
  CTreeParameterArray& loecal;
  CTreeParameter& icent;
  CTreeParameter& dcent;
  CTreeParameter& imax;
  CTreeParameter& dmax;
  CTreeParameter& imaxch;
  CTreeParameter& dmaxch;
  CTreeParameter& imult;
  CTreeParameter& dmult;
  CTreeParameter& isum;
  CTreeParameter& dsum;
};

/* SSSD */
struct sssd
{
  CTreeParameterArray& hienergy;
  CTreeParameterArray& hiecal;
  CTreeParameterArray& loenergy;
  CTreeParameterArray& loecal;
  CTreeParameter& hicent;
  CTreeParameter& himax;
  CTreeParameter& himaxch;
  CTreeParameter& himult;
  CTreeParameter& hisum;
  CTreeParameter& locent;
  CTreeParameter& lomax;
  CTreeParameter& lomaxch;
  CTreeParameter& lomult;
  CTreeParameter& losum;
};

/* Total */
struct total
{
  CTreeParameter& dsum;
  CTreeParameter& dmax;
  CTreeParameter& isum;
  CTreeParameter& imax;
};

/* SeGA detectors */
struct sega
{
  CTreeParameterArray& energy;
  CTreeParameterArray& time;
  CTreeParameterArray& ecal;
};

/* Total gamma energy */
struct segatotal
{
  CTreeParameter& mult;
  CTreeParameter& total;
  CTreeParameter& tot11;
  CTreeParameter& xmatrix;
  CTreeParameter& ymatrix;
};

/* TAC outputs */
struct tac
{
  CTreeParameter& rf;
  CTreeParameter& ge;
  CTreeParameter& i2stof;
  CTreeParameter& i2ntof;
  CTreeParameter& i2scorr;
  CTreeParameter& i2ncorr;
  CTreeParameter& i2pos;
};

/* Implant-decay correlation */
struct correlator
{
  CTreeParameter& dtimplant;
  CTreeParameter& itime;
  CTreeParameter& ide1;
  CTreeParameter& ide2;
  CTreeParameter& ide3;
  CTreeParameter& ide4;
  CTreeParameter& iisum;
  CTreeParameter& iimax;
  CTreeParameter& itof;
  CTreeParameter& dtime;
  CTreeParameter& dde1;
  CTreeParameter& dde2;
  CTreeParameter& dde3;
  CTreeParameter& dde4;
  CTreeParameter& disum;
  CTreeParameter& dimax;
  CTreeParameter& dtof;
  CTreeParameter& dtimecal;
  CTreeParameter& flag1;
};

/* PID */
struct pid
{
  CTreeParameter& i2stof;
  CTreeParameter& i2ntof;
  CTreeParameter& rftof;
  CTreeParameter& xfptof;
  CTreeParameter& de0;
  CTreeParameter& de1;
  CTreeParameter& de2;
  CTreeParameter& de3;
  CTreeParameter& de4;
  CTreeParameter& isum;
  CTreeParameter& imax;
};

/* Temperature monitor */
struct temperature
{
  CTreeParameter& temp;
  CTreeParameter& clock;
};

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


/* The entire beta-decay set-up */
struct betadecay
{
  struct bit bit;
  struct clock clock;
  struct adc adc;
  struct tdc tdc;
  struct pin pin00;
  struct pin pin01;
  struct pin pin02;
  struct pin pin03;
  struct pin pin04;
  struct scint n3scint;
  struct RF rf;
  struct i2sci i2s;
  struct i2sci i2n;
  struct ger ge;
  struct dssd front;
  struct dssd back;
  struct sssd sssd1;
  struct total total;
  struct sega sega;
  struct segatotal segatotal;
  struct tac tac;
  struct correlator corr;
  struct pid pid;
  struct temperature temp;
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

extern struct betadecay bdecay;
extern struct detector nero;
#endif
