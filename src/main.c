#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mult.h"
#include "matrix.h"

#define RESET "\033[0m"
#define RED   "\033[1;31m"

double calcCodeSectionDeltaTime(clock_t begin, clock_t end)
{
	return (double)(end - begin) / CLOCKS_PER_SEC;
}

int main(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("%sERROR%s : Enter the size of the matrices, rows and cols.", RED, RESET);
		printf(" Example: 5 2 2 3.\n");
		return 1;
	}

	// MAIN PARAMETERS CONVERTION
	int matARows = atoi(argv[1]);
	int matACols = atoi(argv[2]);
	int matBRows = atoi(argv[3]);
	int matBCols = atoi(argv[4]);

	if (matACols != matBRows)
	{
		printf("%sERROR%s : Matrices A and B can be multiplied if they are compatible in the sense that the number of columns of matrix A is equal to the number of rows of B.\n", RED, RESET);
		return 1;
	}

	// MEMORY ALLICATION
	double **matA = matDoubleAllocateMemory(matARows, matACols);
	double **matB = matDoubleAllocateMemory(matBRows, matBCols);
	double **matC = matDoubleAllocateMemory(matARows, matBCols);

	// FILLING MATRICES
	int minMatrixValue = 0;
	int maxMatrixValue = 10;
	matDoubleFillRandom(matA, matARows, matACols, minMatrixValue, maxMatrixValue);
	matDoubleFillRandom(matB, matBRows, matBCols, minMatrixValue, maxMatrixValue);

	// DISPLAYING THE SOUCE MATRICES
	printf("Matrix A:\n");
	matDoubleDisplay(matA, matARows, matACols);
	printf("Matrix B:\n");
	matDoubleDisplay(matB, matBRows, matBCols);

	// MATRICES MULTIPLICATION
	clock_t begin = clock();
	multMultiplyIntMatrices(matA, matB, matC, matARows, matACols, matBRows, matBCols);
	clock_t end = clock();
	printf("Code work time : %f sec\n", calcCodeSectionDeltaTime(begin, end));
	//matDoubleDisplay(matC, matARows, matBRows);

    double *nowcolumn = (double *)calloc(matBRows, sizeof(double));
    begin = clock();
	multMultiply2IntMatrices(nowcolumn,matA, matB, matC, matARows, matACols, matBRows, matBCols);
    end = clock();
    free(nowcolumn);
	printf("Second variant code work time : %f sec\n", calcCodeSectionDeltaTime(begin, end));
    //matDoubleDisplay(matC, matARows, matBRows);

	double *nowrow = (double *)calloc(matACols, sizeof(double));
	begin = clock();
	multMultiply3IntMatrices(nowrow,matA, matB, matC, matARows, matACols, matBRows, matBCols);
    end = clock();
    free(nowrow);
	printf("Third variant code work time : %f sec\n", calcCodeSectionDeltaTime(begin, end));
	//matDoubleDisplay(matC, matARows, matBRows);

	nowcolumn = (double *)calloc(matBRows, sizeof(double));
	nowrow = (double *)calloc(matACols, sizeof(double));
	begin = clock();
	multMultiply4IntMatrices(nowcolumn,nowrow,matA, matB, matC, matARows, matACols, matBRows, matBCols);
    end = clock();
    free(nowrow);
    free(nowcolumn);
	printf("Fourth variant code work time : %f sec\n", calcCodeSectionDeltaTime(begin, end));
	//matDoubleDisplay(matC, matARows, matBRows);


	//printf("Matrix C:\n");
	//matDoubleDisplay(matC, matARows, matBCols);

	// MEMORY DEALLICATION
	matDoubleFreeMemory(matA, matARows);
	matDoubleFreeMemory(matB, matBRows);
	matDoubleFreeMemory(matC, matARows);

	return 0;
}
