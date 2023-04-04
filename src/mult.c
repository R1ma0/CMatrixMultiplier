#include "mult.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>

double multMultiplyIntMatrices(int **matA, int **matB, int **matC, int aRows, int aCols, int bRows, int bCols)
{
	clock_t time = 0.0;
	clock_t begin;
	clock_t end;

	begin = clock();
	
	for (int r = 0; r < aRows; r++)
	{
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0;
			// aCols == bRows
			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += matA[r][i] * matB[i][c];
			}
		}
	}

	end = clock();
	
	return (double)(end - begin) / CLOCKS_PER_SEC;
}

double multMultiply2IntMatrices(int *nowcolumn, int **matA, int **matB, int **matC, int aRows, int aCols, int bRows, int bCols)
{
	clock_t time = 0.0;
	clock_t begin;
	clock_t end;

	begin = clock();
	
	for (int r = 0; r < aRows; r++)
	{
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0;
			// aCols == bRows
			for (int i = 0; i < bRows; i++) 
			{
				nowcolumn[i] = matB[i][c];
				matC[r][c] += matA[r][i] * nowcolumn[i];
			}
		}
	}

	end = clock();

	return (double)(end - begin) / CLOCKS_PER_SEC;
}

double multMultiply3IntMatrices(int *nowrow, int **matA, int **matB, int **matC, int aRows, int aCols, int bRows, int bCols)
{
	clock_t time = 0.0;
	clock_t begin;
	clock_t end;

	begin = clock();
	

	for (int r = 0; r < aRows; r++)
	{
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0;
			// aCols == bRows
			for (int i = 0; i < aCols; i++) 
			{
				nowrow[i] = matA[r][i];
			}
			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += nowrow[i] * matB[i][c];
			}
		}
	}

	end = clock();
	return (double)(end - begin) / CLOCKS_PER_SEC;
}

double multMultiply4IntMatrices(int *nowcolumn, int *nowrow, int **matA, int **matB, int **matC, int aRows, int aCols, int bRows, int bCols)
{
	clock_t time = 0.0;
	clock_t begin;
	clock_t end;

	begin = clock();

	for (int r = 0; r < aRows; r++)
	{
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0;
			// aCols == bRows
			for (int i = 0; i < aCols; i++) 
			{
				nowrow[i] = matA[r][i];
				nowcolumn[i] = matB[i][c];

			}
			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += nowrow[i] * nowcolumn[i];
			}
		}
	}
	
	end = clock();
	return (double)(end - begin) / CLOCKS_PER_SEC;
}
