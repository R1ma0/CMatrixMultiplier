#include "mult.h"
#include <malloc.h>

void multMultiplyIntMatrices(int **matA, int **matB, int **matC, int aRows, int aCols, int bRows, int bCols)
{
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
}

void multMultiply2IntMatrices(int *nowcolumn, int **matA, int **matB, int **matC, int aRows, int aCols, int bRows, int bCols)
{

	for (int r = 0; r < aRows; r++)
	{
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0;
			// aCols == bRows
			for (int i = 0; i < bRows; i++) //Проходим по столбцу в матрице-Б
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

void multMultiply3IntMatrices(int *nowrow, int **matA, int **matB, int **matC, int aRows, int aCols, int bRows, int bCols)
{
	for (int r = 0; r < aRows; r++)
	{
	    for (int i = 0; i < aCols; i++) //Проходим по строке в матрице-А
		{
			nowrow[i] = matA[r][i];
		}
		
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0;
			// aCols == bRows
			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += nowrow[i] * matB[i][c];
			}
		}
	}
}

void multMultiply4IntMatrices(int *nowcolumn, int *nowrow, int **matA, int **matB, int **matC, int aRows, int aCols, int bRows, int bCols)
{
	for (int r = 0; r < aRows; r++)
	{
	    for (int i = 0; i < aCols; i++) //Проходим по строке в матрице-А
		{
			nowrow[i] = matA[r][i];
		}
		
		for (int c = 0; c < bCols; c++)
		{
			matC[r][c] = 0;
			// aCols == bRows
			for (int i = 0; i < aCols; i++) //Проходим по строке в матрице-А
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
