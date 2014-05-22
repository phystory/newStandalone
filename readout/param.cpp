static char rcsId[]="$Id: param.cpp,v 2.0 2002/11/13 22:47:41 a1900 Exp $";

#include <stddef.h>
#include <stdlib.h> 

#include <stdio.h>
#include <string.h>

#include <tcl.h>

#include "param.h"


static Tcl_Interp *ourInterp=NULL;

int Param_readFile(char *fileName) {
	if (ourInterp == NULL) {
		ourInterp = Tcl_CreateInterp();
	}
	if (Tcl_EvalFile(ourInterp, fileName) == TCL_OK) {
		return 0;
	} else {
		fprintf(stdout, "%s\n", ourInterp->result);
		return -1;
	}
}

double Param_getVal(const char *name, const char *index) {
        const char *string;

	string = Tcl_GetVar2(ourInterp, (const char *)name, (const char *)index, 0);
	if (string != NULL) {
		return atof(string);
	} else {
		fprintf(stdout, "Unknown Parameter '%s(%s)', using 0.0\n", name, index);
		return 0;
	}
}

int Param_getIntVal(const char *name, const char *index) {
	const char *string;

	string = Tcl_GetVar2(ourInterp,(const char *)name, (const char *)index, 0);
	if (string != NULL) {
		return atoi(string);
	} else {
		fprintf(stdout, "Unknown Parameter '%s(%s)', using 0.0\n", name, index);
		return 0;
	}
}

char * Param_getStrVal(const char *name, const char *index) {
	char *string;

	string = (char *)Tcl_GetVar2(ourInterp,(const char *)name, (const char *)index, 0);
	if (string != NULL) {
		return string;
	} else {
		fprintf(stdout, "Unknown Parameter '%s(%s)', using unknown\n", name, index);
		return "unknown";
	}
}

void getline(FILE *fp,char line[])
{ 
    char c;
    int i;
    i=0;
    c=' ';
    while ((!feof(fp))&&(c!='\n'))
    {
       c=fgetc(fp);
       line[i]=c;
       i++;
    }
    line[i]='\0';
}


