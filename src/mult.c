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
		for (int i = 0; i < bRows; i++)
		{
			nowcolumn[i] = matB[i][bc];
		}

		for (int ar = 0; ar < aRows; ar++)
		{
			for (int j = 0; j < bRows; j++)
			{
				matC[ar][bc] += matA[ar][j] * nowcolumn[j];
			}
		}
	}

	//for (int ar = 0; ar < aRows; ar++)
	//{
	//	for (int bc = 0; bc < bCols; bc++)
	//	{
	//		for (int i = 0; i < bRows; i++)
	//		{
	//			nowcolumn[i] = matB[i][bc];
	//		}

//			for (int j = 0; j < bRows; j++)
//			{
//				matC[ar][bc] += matA[ar][j] * nowcolumn[j];
//			}
//		}
//	}
			
	cwt.end = clock();
	return calcCodeWorkingTimeDelta(cwt);
}

double multMultiplyARowB(double *nowrow, double **matA, double **matB, double **matC, int aRows, int aCols, int bRows, int bCols)
{
	CodeWorkingTime cwt;
	cwt.begin = clock();

	for (int r = 0; r < aRows; r++)
	{
	    for (int i = 0; i < aCols; i++) 
		{
			nowrow[i] = matA[r][i];
		}
		
		for (int c = 0; c < bCols; c++)
		{
			// aCols == bRows
			for (int i = 0; i < aCols; i++)
			{
				matC[r][c] += nowrow[i] * matB[i][c];
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

	for (int r = 0; r < aRows; r++)
	{
	    for (int i = 0; i < aCols; i++) 
		{
			nowrow[i] = matA[r][i];
		}
		
		for (int c = 0; c < bCols; c++)
		{
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

	cwt.end = clock();
	return calcCodeWorkingTimeDelta(cwt);
}
