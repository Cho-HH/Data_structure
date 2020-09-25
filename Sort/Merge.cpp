#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i = 0;

	int* sortArr = (int*)malloc(sizeof(int)*(right+1));
	int sIdx = left; //저장될 메모리공간의 인덱스

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for (i = fIdx; i < mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];
	free(sortArr);
}
void MergeSort(int arr[], int left, int right)
//left : 첫번째 요소, right: 마지막 요소
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		//둘로 나눠서 정렬
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}