#include <stdio.h>
#include <stdlib.h>
#include "mult.h"
#include "matrix.h"

#define RESET "\033[0m"
#define RED   "\033[1;31m"

int main(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("%sERROR%s : Enter the size of the matrices, rows and cols.", RED, RESET);
		printf(" Example: 2 2 5 3.\n");
		return 1;
	} 

	int matARows = atoi(argv[1]);
	int matACols = atoi(argv[2]);
	int matBRows = atoi(argv[3]);
	int matBCols = atoi(argv[4]);

	int **matA = matIntAllocateMemory(matARows, matACols);
	int **matB = matIntAllocateMemory(matBRows, matBCols);
	int **matC = matIntAllocateMemory(matARows, matBCols);

	int minMatrixValue = 0;
	int maxMatrixValue = 10;
	matIntFillRandom(matA, matARows, matACols, minMatrixValue, maxMatrixValue);
	matIntFillRandom(matB, matBRows, matBCols, minMatrixValue, maxMatrixValue);

	printf("Matrix A:\n");
	matIntDisplay(matA, matARows, matACols);
	printf("Matrix B:\n");
	matIntDisplay(matB, matBRows, matBCols);

	matIntFreeMemory(matA, matARows);
	matIntFreeMemory(matB, matBRows);
	matIntFreeMemory(matC, matARows);

	return 0;
}
