#include "mult.h"

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
