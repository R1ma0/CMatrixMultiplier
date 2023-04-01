#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"

int **matIntAllocateMemory(int rows, int cols)
{
	int **mat = (int **)calloc(rows, sizeof(int *));
	for (int r = 0; r < rows; r++)
	{
		mat[r] = (int *)calloc(cols, sizeof(int *));
	}

	return mat;
}

void matIntFreeMemory(int **matrix, int rows)
{
	for (int r = 0; r < rows; r++)
	{
		free(matrix[r]);
	}
	free(matrix);
}

void matIntFillRandom(int **matrix, int rows, int cols, int min, int max)
{
	srand(time(NULL));

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			matrix[r][c] = min + rand() % max;
		}
	}
}

void matIntDisplay(int **matrix, int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			printf("%5d", matrix[r][c]);
		}
		printf("\n");
	}
}
