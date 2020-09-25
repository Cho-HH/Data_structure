#include <stdio.h>

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; //가장 왼쪽
	int low = left + 1;
	int high = right;
	while (low <= high) //low > high일 때까지 반복
	{ //피벗보다 큰 값을 찾을때까지
		while (pivot >= arr[low] && low <= right)
			low++; //low를 오른쪽으로

		while (pivot <= arr[high] && high >= (left + 1))
			high--;

		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);//피벗과 high의 데이터 교환
	return high;
}

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}
void QuickSort(int arr[],int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}