#ifndef MULT_H
#define MULT_H

#include <malloc.h>
#include <time.h>

typedef struct
{
	clock_t begin;
	clock_t end;
} CodeWorkingTime;

double calcCodeWorkingTimeDelta(CodeWorkingTime);
double multMultiplyAB(double **, double **, double **, int, int, int, int);
double multMultiplyABCol(double *, double **, double **, double **, int, int, int, int);
double multMultiplyARowB(double *, double **, double **, double **, int, int, int, int);
double multMultiplyARowBCol(double *, double *, double **, double **, double **, int, int, int, int);

#endif // MULT_H
