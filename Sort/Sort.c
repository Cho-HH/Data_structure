#include <stdio.h>

//오름차순
void BubbleSort(int arr[])
{
	int arrSize = sizeof(arr) / sizeof(int);

	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
				
		}
	}
}

void SelectSort(int arr[])
{
	int arrSize = sizeof(arr) / sizeof(int);

	for (int i = 0; i < arrSize - 1; i++)
	{
		int min = i;
		for (int j = arrSize - 1; j >= i; j--)
			if (arr[min] > arr[j])
				min = j;

		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void InsertSort(int arr[])
{
	int arrSize = sizeof(arr) / sizeof(int);
	int j;
	for (int i = 1; i < arrSize; i++)
	{
		int insData = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[i] < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
	}
}