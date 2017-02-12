#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000
#define S_OK 0

enum CaseLevel
{
	ECaseLevelNone = 0,
	ECaseLevelBest = 1,
	ECaseLevelWorst = 2,
	ECaseLevelRandom = 3,
	ECaseLevelAll
};

int CreateCase(int *pArray, int caselevel)
{
	int i = 0;
	if (caselevel == ECaseLevelBest)
	{
		for (i = 0; i < MAX_NUM; i++)
		{
			pArray[i] = i + 1;
		}
	}
	else if (caselevel = ECaseLevelWorst)
	{
		for (i = 0; i < MAX_NUM; i++)
		{
			pArray[i] = MAX_NUM - i;
		}
	}
	else if (caselevel = ECaseLevelRandom)
	{
		for (i = 0; i < MAX_NUM; i++)
		{
			pArray[i] = (rand() % MAX_NUM) + 1;
		}
	}
	else
	{
		printf ("Failed\n");
	}
	return S_OK;
}

int DisplayCase(int *pArray)
{
	int i = 0;
	for (i = 0; i < MAX_NUM; i++)
	{
		printf ("%d ", pArray[i]);
	}
	printf("\n");
	return S_OK;
}

int swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return S_OK;
}

int Selection_Sort(int *pArray)
{
	int i = 0, j = 0;
	struct timeval stime, etime;
	gettimeofday(&stime, NULL);
	int iMinIndex, iMinVal;

	for (i = 0; i < MAX_NUM; i++)
	{
		iMinIndex = i;
		iMinVal = pArray[i];
		for (j = i + 1; j < MAX_NUM; j++)
		{
			if (iMinVal > pArray[j])
			{
				iMinIndex = j;
				iMinVal = pArray[j];
			}
		}
		if (i == iMinIndex)
			continue;
		swap(&(pArray[i]), &(pArray[iMinIndex]));
	}

	gettimeofday(&etime, NULL);

	printf ("Time difference is %06ld.%06ld\n", etime.tv_sec - stime.tv_sec, etime.tv_usec - stime.tv_usec);
	return S_OK;
}

int main()
{
	int Array[MAX_NUM];
	int iCaseOption = 0;
	srand(0);

	printf ("Enter the level to set the case\n1. Best Case\n2. Worst Case\n3. Random Case\n");
	scanf("%d", &iCaseOption);
	CreateCase(Array, iCaseOption);

	//printf ("This is initial array\n");
	//DisplayCase(Array);
	Selection_Sort(Array);

	printf ("This is Selection sort array\n");
	DisplayCase(Array);

	return S_OK;
}
