#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"

double **matDoubleAllocateMemory(int rows, int cols)
{
	double **mat = (double **)calloc(rows, sizeof(double *));
	for (int r = 0; r < rows; r++)
	{
		mat[r] = (double *)calloc(cols, sizeof(double *));
	}

	return mat;
}

void matDoubleFreeMemory(double **matrix, int rows)
{
	for (int r = 0; r < rows; r++)
	{
		free(matrix[r]);
	}
	free(matrix);
}

void matDoubleFillRandom(double **matrix, int rows, int cols, int min, int max)
{
	srand(time(NULL));

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			matrix[r][c] = min + (max - min) * (rand() % max) / max;
		}
	}
}

void matDoubleDisplay(double **matrix, int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			printf("%5.2f", matrix[r][c]);
		}
		printf("\n");
	}
}
