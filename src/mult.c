#include "mult.h"

double calcCodeWorkingTimeDelta(CodeWorkingTime cwt)
{
	return (double)(cwt.end - cwt.begin) / CLOCKS_PER_SEC;
}

double multMultiplyAB(double **matA, double **matB, double **matC, int aRows, int aCols, int bRows, int bCols)
{
	CodeWorkingTime cwt;
	cwt.begin = clock();

	for (int r = 0; r < aRows; r++)
	{
		for (int c = 0; c < bCols; c++)
		{
			// aCols == bRows
			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += matA[r][i] * matB[i][c];
			}
		}
	}

	cwt.end = clock();
	return calcCodeWorkingTimeDelta(cwt);
}

double multMultiplyABCol(double *nowcolumn, double **matA, double **matB, double **matC, int aRows, int aCols, int bRows, int bCols)
{
	CodeWorkingTime cwt;
	cwt.begin = clock();

	for (int bc = 0; bc < bCols; bc++)
	{
		for (int br = 0; br < bRows; br++)
		{
			nowcolumn[br] = matB[br][bc];
		}

		for (int ar = 0; ar < aRows; ar++)
		{
			for (int ac = 0; ac < aCols; ac++)
			{
				matC[ar][bc] += matA[ar][ac] * nowcolumn[ac];
			}
		}
	}
		
	cwt.end = clock();
	return calcCodeWorkingTimeDelta(cwt);
}

double multMultiplyARowB(double *nowrow, double **matA, double **matB, double **matC, int aRows, int aCols, int bRows, int bCols)
{
	CodeWorkingTime cwt;
	cwt.begin = clock();

	for (int ar = 0; ar < aRows; ar++)
	{
	    for (int ac = 0; ac < aCols; ac++) 
		{
			nowrow[ac] = matA[ar][ac];
		}
		
		for (int bc = 0; bc < bCols; bc++)
		{
			for (int br = 0; br < bRows; br++)
			{
				matC[ar][bc] += matB[br][bc] * nowrow[br];
			}
		}
	}

	cwt.end = clock();
	return calcCodeWorkingTimeDelta(cwt);
}

double multMultiplyARowBCol(double *nowcolumn, double *nowrow, double **matA, double **matB, double **matC, int aRows, int aCols, int bRows, int bCols)
{
	CodeWorkingTime cwt;
	cwt.begin = clock();

	for (int ar = 0; ar < aRows; ar++)
	{
	    for (int ac = 0; ac < aCols; ac++) 
		{
			nowrow[ac] = matA[ar][ac];
		}

		for (int bc = 0; bc < bCols; bc++)
		{
			for (int br = 0; br < bRows; br++) 
			{
				nowcolumn[br] = matB[br][bc];
			}

			for (int i = 0; i < aCols; i++)
			{
				matC[ar][bc] += nowrow[i] * nowcolumn[i];
			}
		}
	}

	cwt.end = clock();
	return calcCodeWorkingTimeDelta(cwt);
}
