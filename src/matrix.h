#ifndef ARRAY_H
#define ARRAY_H

double **matDoubleAllocateMemory(int, int);
void matDoubleFreeMemory(double **, int);
void matDoubleFillRandom(double **, int, int, int, int);
void matDoubleDisplay(double **, int, int);

#endif // ARRAY_H
