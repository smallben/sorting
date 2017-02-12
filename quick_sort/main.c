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

int Quick_Sort(int *pArray, int left, int right)
{
	int i = 0, j = 0, pivot = 0;
	//struct timeval stime, etime;
	//gettimeofday(&stime, NULL);

	if (left >= right)
	{
		return S_OK;
	}

	pivot = pArray [left];

	i = left + 1;
	j = right;

	while (1)
	{
		while (i <= right)
		{
			//left need always smaller than pivot
			//otherwise, SWAP
			if (pArray[i] > pivot)
			{
				break;
			}

			i += 1;
		}

		while (j > left)
		{
			//right need always larger than pivot
			//otherwise, SWAP
			if (pArray[j] < pivot)
			{
				break;
			}

			j -= 1;
		}

		//The left index over than right index. break;
		if (i > j)
		{
			break;
		}

		swap (&(pArray[i]), &(pArray[j]));
	}

	// move the pivot to the middle place
	if (left != j)
		swap (&(pArray[left]), &(pArray[j]));

	//Divide and Conquer
	Quick_Sort(pArray, left, j - 1);
	Quick_Sort(pArray, j + 1, right);


	//gettimeofday(&etime, NULL);

	//printf ("Time difference is %06ld.%06ld\n", etime.tv_sec - stime.tv_sec, etime.tv_usec - stime.tv_usec);
	return S_OK;
}

int main()
{
	int Array[MAX_NUM];
	int iCaseOption = 0;

	printf ("Enter the level to set the case\n1. Best Case\n2. Worst Case\n3. Random Case\n");
	scanf("%d", &iCaseOption);
	CreateCase(Array, iCaseOption);

	//printf ("This is initial array\n");
	//DisplayCase(Array);
	Quick_Sort(Array, 0, MAX_NUM - 1);

	printf ("This is Quick sort array\n");
	DisplayCase(Array);

	return S_OK;
}
