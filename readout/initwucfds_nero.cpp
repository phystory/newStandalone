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
//#include <slvshared.h>

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
#endif
*/
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

/* initwucfds (the special ones from WU)
 * Marc-Jan van Goethem NSCL (2001)
 * Version 2.0	
 *	-added selection of the channel on the test output 
 *	 note that data-file format has changed.
 * 	-removed the update version 
 * This routine should either be called from initevt() (in skeleton.cpp)
 * or conditionally from another point in Readout, the conditionflag could
 * for instance be a TCL variable, signalling if the file with shaper data has
 * changed. It can for instance be checked every time the scalers are readout
 * (provided they are readout). In the latter case one does not have to restart
 * the DAQ each time the gaines are changed.
 *
 * CFD datafile format:
 * Comment Line (Anything but + as first letter !)
 * branch crate slot channel
 * d1 d2 d3 d4
 * d5 d6 d7 d8
 * d9 d10 d11 d12
 * d13 d14 d15 d16
 * branch crate slot channel
 * d1 d2 d3 d4
 * ...
 * ...		(repeat for every CFD module)
 * +++++++++	-Marks the end of the file-
*/

#define MAX_CFD 16

int initwucfds_nero()
{
   std::ifstream fp;
   int isl[MAX_CFD];     /* list of slot numbers  */
   int ibr[MAX_CFD];     /* list of branch numbers */
   int icr[MAX_CFD]; 	 /* list of crate numbers */
   int isel[MAX_CFD];	 /* list of channels selected on the test output */
   int uw[MAX_CFD][16];  /* list of user data (N.B. 8 bits !!) */
   int ncfd;
   int i,j;
   int ic;
   char line[128];



   printf("Initialize CFD:\n");
   printf("\n");   

   /* Read cfd data from file 
    * We can make this much fancier later if we want to.
    */
   i=0;
   fp.open("cfd_init_nero.dat",std::ios::in);
   if (fp==NULL) return 0; 
   while (!fp.eof())
   {   
     fp.getline(line,127);
     printf("%s",line);
     if (line[0]=='+') goto done;

     fp.getline(line,127);
     printf("%s",line);
     
     sscanf(line," %d %d %d %d ",&ibr[i],&icr[i],&isl[i],&isel[i]);  
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
     printf("CFD %d :",i);
     printf("%d %d %d \n",ibr[i],icr[i],isl[i]);   
     i++;
     if (i>=MAX_CFD) {
        printf("OOps i have room for 16 CFDS you'll have to hack\n");
	printf("the code if you want to use more\n");
	exit(1);
     }
   }
   done:
   ncfd=i;
   fp.close();

   /* Loop over all cfd modules and all channels*/
   for (i=0; i<ncfd; i++)
   {

     int iw;
     for (j=0; j<16; j++)
       {
         if (uw[i][j]>255) uw[i][j]=255;
	 if (uw[i][j]<0) uw[i][j]=0;
         camwrite16(ibr[i],icr[i],isl[i],j,17,uw[i][j]); 
	 iw=camread16(ibr[i],icr[i],isl[i],0,1);
       }
     /* select test output channel*/
     if (isel[i]==0) 
       { 
	 /* no channel selected */
	 /* put a 1xx1 1xxx --> 1111 1111 = 0xFF */
	 camwrite16(ibr[i],icr[i],isl[i],0,16,0x00FF);	/* register is only 8 bits */
	 printf("CFD %d %d %d has no test output selected\n",ibr[i],icr[i],isl[i]);
       }
     else
       {
	 int dd=0;
	 if ((isel[i]>8)&&(isel[i]<=16))
	   {
	     dd=isel[i]-1;	/* count from 0 --> -1 */
	   }
	 if (isel[i]<=8) 
	   {
	     dd=isel[i]+15;	/* set bit 5 and count from 0 --> +16 -1 */
	   }
	 dd=dd&0x00FF;		/* register is only 8 bits wide */
	 //          printf("debug %d\n",dd);
	 camwrite16(ibr[i],icr[i],isl[i],0,16,dd);
	 printf("CFD %d %d %d has channel %d on the test output\n",ibr[i],icr[i],isl[i],isel[i]);
       }
     
     
   }
   printf("Done with CFDS....\n\n");
   return 1;
}
