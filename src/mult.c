#include "mult.h"
#include <malloc.h>

double multMultiplyIntMatrices(double **matA, double **matB, double **matC, int aRows, int aCols, int bRows, int bCols)
{
	for (int r = 0; r < aRows; r++)
	{
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0.0;
			// aCols == bRows
			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += matA[r][i] * matB[i][c];
			}
		}
	}
}

double multMultiply2IntMatrices(double *nowcolumn, double **matA, double **matB, double **matC, int aRows, int aCols, int bRows, int bCols)
{
	for (int r = 0; r < aRows; r++)
	{
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0.0;

			for (int i = 0; i < bRows; i++) 
			{
				nowcolumn[i] = matB[i][c];
			}

			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += matA[r][i] * nowcolumn[i];
			}
		}
	}
}

double multMultiply3IntMatrices(double *nowrow, double **matA, double **matB, double **matC, int aRows, int aCols, int bRows, int bCols)
{
	for (int r = 0; r < aRows; r++)
	{
	    for (int i = 0; i < aCols; i++) 
		{
			nowrow[i] = matA[r][i];
		}
		
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0.0;
			// aCols == bRows
			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += nowrow[i] * matB[i][c];
			}
		}
	}
}

double multMultiply4IntMatrices(double *nowcolumn, double *nowrow, double **matA, double **matB, double **matC, int aRows, int aCols, int bRows, int bCols)
{
	for (int r = 0; r < aRows; r++)
	{
	    for (int i = 0; i < aCols; i++) 
		{
			nowrow[i] = matA[r][i];
		}
		
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0.0;

			for (int i = 0; i < aCols; i++) 
			{
				nowcolumn[i] = matB[i][c];

			}

			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += nowrow[i] * nowcolumn[i];
			}
		}
	}
}
