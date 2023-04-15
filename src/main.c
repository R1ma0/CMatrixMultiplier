#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mult.h"
#include "matrix.h"

#define RESET "\033[0m"
#define RED   "\033[1;31m"

int main(int argc, char **argv)
{
	// MATRIX DISPLAY OPTION
	int isMatrixDisplayed = 0; // 0 - no, 1 - yes
	
	int minMatrixValue = 0;
	int maxMatrixValue = 9;

	int matARows;
	int matACols;
	int matBRows;
	int matBCols;

	double **matA;
	double **matB;
	double **matC;

	double codeWorkTime;

	if (argc < 5)
	{
		printf("%sERROR%s : Enter the size of the matrices, rows and cols.", RED, RESET);
		printf(" Example: 5 2 2 3.\n");
		return 1;
	}

	if (argc > 5 && strcmp(argv[5], "--display=yes") == 0)
	{
		isMatrixDisplayed = 1;
	}

	// MAIN PARAMETERS CONVERTION
	matARows = atoi(argv[1]);
	matACols = atoi(argv[2]);
	matBRows = atoi(argv[3]);
	matBCols = atoi(argv[4]);

	if (matACols != matBRows)
	{
		printf("%sERROR%s : Matrices A and B can be multiplied if they are compatible in the sense that the number of columns of matrix A is equal to the number of rows of B.\n", RED, RESET);
		return 1;
	}

	// MEMORY ALLICATION
	matA = matDoubleAllocateMemory(matARows, matACols);
	matB = matDoubleAllocateMemory(matBRows, matBCols);
	matC = matDoubleAllocateMemory(matACols, matBRows);

	// FILLING MATRICES
	matDoubleFillRandom(matA, matARows, matACols, minMatrixValue, maxMatrixValue);
	sleep(1);
	matDoubleFillRandom(matB, matBRows, matBCols, minMatrixValue, maxMatrixValue);
	matDoubleFillZero(matC, matACols, matBRows);

	// DISPLAYING THE SOUCE MATRICES
	if (isMatrixDisplayed)
	{
		printf("Matrix A:\n");
		matDoubleDisplay(matA, matARows, matACols);
		printf("Matrix B:\n");
		matDoubleDisplay(matB, matBRows, matBCols);
	}

	// MATRICES MULTIPLICATION
	codeWorkTime = multMultiplyAB(matA, matB, matC, matARows, matACols, matBRows, matBCols);
	printf("Code work time : %f sec\n", codeWorkTime);
	if (isMatrixDisplayed)
	{
		matDoubleDisplay(matC, matACols, matBRows);
	}
	matDoubleFillZero(matC, matACols, matBRows);

    double *nowcolumn = (double *)calloc(matBRows, sizeof(double));
	codeWorkTime = multMultiplyABCol(nowcolumn,matA, matB, matC, matARows, matACols, matBRows, matBCols);
    free(nowcolumn);
	printf("Second variant code work time : %f sec\n", codeWorkTime);
	if (isMatrixDisplayed)
	{
		matDoubleDisplay(matC, matACols, matBRows);
	}
	matDoubleFillZero(matC, matACols, matBRows);

	double *nowrow = (double *)calloc(matACols, sizeof(double));
	codeWorkTime = multMultiplyARowB(nowrow,matA, matB, matC, matARows, matACols, matBRows, matBCols);
    free(nowrow);
	printf("Third variant code work time : %f sec\n", codeWorkTime);
	if (isMatrixDisplayed)
	{
		matDoubleDisplay(matC, matACols, matBRows);
	}
	matDoubleFillZero(matC, matACols, matBRows);

	nowcolumn = (double *)calloc(matBRows, sizeof(double));
	nowrow = (double *)calloc(matACols, sizeof(double));
	codeWorkTime = multMultiplyARowBCol(nowcolumn,nowrow,matA, matB, matC, matARows, matACols, matBRows, matBCols);
    free(nowrow);
    free(nowcolumn);
	printf("Fourth variant code work time : %f sec\n", codeWorkTime);
	if (isMatrixDisplayed)
	{
		matDoubleDisplay(matC, matACols, matBRows);
	}

	// MEMORY DEALLICATION
	matDoubleFreeMemory(matA, matARows);
	matDoubleFreeMemory(matB, matBRows);
	matDoubleFreeMemory(matC, matACols);

	return 0;
}
