/*
**
**  
INCLUDE FILES
**
*/

#include <config.h>

#include <wienercamac.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#ifndef __unix__
#include "cpus.h"
#endif

//#include <lcldaqtypes.h>
#include <daqdatatypes.h>
#include <camac.h>
#include <macros.h>
//#include <slvshared.h>  /*don't know if there is a replacement file for this*/

#ifdef VME16
#undef VME16
#endif
#if CPU == MICROPROJECT
#define VME16 0	
#endif

#ifndef __unix__
#include <vme.h>
#endif
#include <buftypes.h>

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif


/* Short circuit run time evaluation of constant BCNAF's */
/*
#ifdef __unix__
#include <camac.h>
extern UINT32 CAMBAS;
#else
#if CPU == IRONICS
#undef CAMBAS
#define CAMBAS(b)	0xFA800000
#endif

#if CPU == MICROPROJECT
#undef CAMBAS
#define CAMBAS(b)	0xFE800000
#endif
#endif*/

/* Next 13 lines of code commented out from CAMBAS error on compilation
   replaced with code above from skeleton.cpp */
// #ifdef __unix__
// #undef CAMBAS
// extern UINT32 CAMBAS;		/* Filled in by harness after mmapping CAMAC */
// #else
// #if CPU == IRONICS
// #undef CAMBAS
// #define CAMBAS	0xFA800000
// #endif

// #if CPU == MICROPROJECT
// #undef CAMBAS
// #define CAMBAS	0xFE800000
// #endif
// #endif

/* initwushapers()
 * Marc-Jan van Goethem NSCL (2001)
 *
 * Version: working (tested with a one shaper setup) 03/28/2001
 *
 * Functional description:
 * 
 * reads a data file shaper_init.dat containing the gain settings of ALL the
 * shapers and initializes the modules with them.
 *
 * Comments:
 * Should be called from initevt in skeleton.cpp 
 * This way it updates the gains every time a run is started with begin.
 * The data file can be edited by a normal text editor.
 * One could consider having the initevt make a copy of the file using
 * the run number and title such one has a record of which gains were used
 * in each run 
 * Working on an updatewushaper function that only updates those shapers
 * whose gain settings or channel on test output selection have been 
 * changed 
 *
 * Format of file
 * 
 * branch crate slot channel_out
 * gain1 gain2 gain3 gain4
 * gain5 gain6 gain7 gain8
 * gain9 gain10 gain11 gain12
 * gain13 gain14 gain15 gain16
 * branch crate slot channel_out
 * gain1 gain2 gain3 gain4
 * ....
 * (repeated for all shapers)
 */
 
#define MAX_SHAPER 16
 
int initwushapers_nero()
{
   std::ifstream fp;
   int isl[MAX_SHAPER];     /* list of slot numbers  */
   int ibr[MAX_SHAPER];     /* list of branch numbers */
   int icr[MAX_SHAPER];     /* list of crate numbers */
   int uw[MAX_SHAPER][16];  /* list of user data (N.B. 8 bits !!) */
   int uw2[MAX_SHAPER];	    /* list of which channel to be put on lemo output*/
   int nshaper=0;
   int i,j;
   int ic,dw1,dw2,ich,icho;
   int ibit,bit,ipo;
   char line[128];
   

   printf("Initialize Shapers:\n");
   printf("\n");   

   i=0;
   fp.open("shaper_init_nero.dat",std::ios::in);
   if (fp==NULL) return 0;   
   while(!fp.eof())
   {
     fp.getline(line,127);
     printf("%s",line);
     if (line[0]=='+') goto done2;
     fp.getline(line,127);
     printf("%s",line);
     sscanf(line," %d %d %d %d ",&ibr[i],&icr[i],&isl[i],&uw2[i]);  
     fp.getline(line,127);
     printf("%s",line);
     sscanf(line," %d %d %d %d  ",&uw[i][0],&uw[i][1],&uw[i][2],&uw[i][3]);
     fp.getline(line,127);
     printf("%s",line);
     sscanf(line," %d %d %d %d  ",&uw[i][4],&uw[i][5],&uw[i][6],&uw[i][7]);
     fp.getline(line,127);
     printf("%s",line);
     sscanf(line," %d %d %d %d  ",&uw[i][8],&uw[i][9],&uw[i][10],&uw[i][11]);
     fp.getline(line,127);
     printf("%s\n",line);
     sscanf(line," %d %d %d %d  ",&uw[i][12],&uw[i][13],&uw[i][14],&uw[i][15]);       
     printf("Shaper %d: ",i+1);
     printf("Branch %d Crate %d Slot %d \n",ibr[i],icr[i],isl[i]);   
     printf("\n");   
     i++;
     if (i>=MAX_SHAPER) {
        printf("Oops -- I have room for 16 shapers; you'll have to \n");
	printf("hack the code if you want to use more.\n");
	exit(1);
     }
   }
   done2:
   nshaper=i;
   fp.close();
   
   /* setting gains */
   /* writing sequence is 
    * (the "d=4,6,4 with a=1 f=16" sequence of 
    * camwrites sends 1 bit to the module) 
    * for each shaper
    *
    * 1) send 1 bit (0)
    * 2) send 1 bit (0)
    * 3) send 8 bits with data (channel 16)
    * 4) send 8 bits with data (channel 15)
    * 5) send 1 bit (0)
    * 6) send 8 bits with data (channel 16) 
    * 7) send 8 bits with data (channel 15)
    * 8) send 1 bit (0)
    * ...
    * ... all other channels 
    * ...
    * 9) do a a=1 f=16 d=0 camwrite to signal ending of writing 
    *    gains to this module
    */
   for (i=0; i<nshaper; i++)
   {
   
     /* send a write cycle */
     printf("Sending the first write to CAMAC; ");
     printf(" %d %d %d %d\n",ibr[i],icr[i],isl[i],uw2[i]);  
     camwrite16(ibr[i],icr[i],isl[i],1,16,4);
     printf("Sending the second write to CAMAC:\n");
     camwrite16(ibr[i],icr[i],isl[i],1,16,6);
     printf("Sending the third write to CAMAC:\n");
     camwrite16(ibr[i],icr[i],isl[i],1,16,4);
     
     ic=0;
     for (j=16; j>=1; j--)
       {
	 ic=ic+1;
	 if (ic==1) 
	   {  
	     ic=-1;
	     if (j>1) 
	       {
	         camwrite16(ibr[i],icr[i],isl[i],1,16,4);
                 camwrite16(ibr[i],icr[i],isl[i],1,16,6);
                 camwrite16(ibr[i],icr[i],isl[i],1,16,4);
	       }
	   }	 
	 ipo=128;	   
	 for (ibit=8; ibit>=1; ibit--)
	   {
	     bit=ipo&uw[i][j-1];	/* j counts from 16 to 1 index 0-15 ! */
	     if (bit>0) bit=1;
	     dw1=bit+4;
	     dw2=bit+6;
	     camwrite16(ibr[i],icr[i],isl[i],1,16,dw1);
	     camwrite16(ibr[i],icr[i],isl[i],1,16,dw2);
	     camwrite16(ibr[i],icr[i],isl[i],1,16,dw1);
	     ipo=ipo/2;
	   }   
       }

     camwrite16(ibr[i],icr[i],isl[i],1,16,0); 
     /* signals end of writing gains to shaper i */
       
     
   } 
   
   /* selection which channel of each shaper should be put on the
    * test output lemo, this is achieved using the a=0 f=16 function
    * where the data is the channel number selected for output + 7.
    * In this code selecting channel 0 means no channels selected (d=128).
    * Channels count from 1 to 16.
    */
   for (i=0; i<nshaper; i++)
   {

     ich=uw2[i];
     if (ich==0)
       {
	 camwrite16(ibr[i],icr[i],isl[i],0,16,128); /* none */
       }
     else
       {
	 icho=ich+7;
	 
	 /* This is sort of the original code but it just seems to add 7 
	  * to ich in a complicated way or am i mistaken ?	  
	  icho=ich-1;
  	  if (ich<=7) 
	  {
	  ifa=8;	/* channels 0-7 map to 8-15 *
	  }
	  else
	  {
	  q  icho-=8;    
	  ifa=16;     /* channels 8-15 map to 16-23 *
	  }
	  icho=ich+ifa;
	 */
	 camwrite16(ibr[i],icr[i],isl[i],0,16,icho);
	 printf("Shaper %d has channel %d on test lemo \n",i,ich);	   
       }
     
   } 
   printf("Done with shapers ...\n\n");
   return 1;
}

