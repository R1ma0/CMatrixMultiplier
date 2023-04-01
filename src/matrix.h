#ifndef ARRAY_H
#define ARRAY_H

int **matIntAllocateMemory(int, int);
void matIntFreeMemory(int **, int);
void matIntFillRandom(int **, int, int, int, int);
void matIntDisplay(int **, int, int);

#endif // ARRAY_H
