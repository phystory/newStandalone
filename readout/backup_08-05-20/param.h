#ifndef MPARAM_H
#define MPARAM_H

int Param_readFile(char *fileName);
double Param_getVal(const char *name, const char *index);
int Param_getIntVal(const char *name, const char *index);
char *Param_getStrVal(const char *name, const char *index);
void getline(FILE *fp,char line[]);

#endif

#include <config.h>

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

