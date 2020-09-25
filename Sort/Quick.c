#include <stdio.h>

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; //���� ����
	int low = left + 1;
	int high = right;
	while (low <= high) //low > high�� ������ �ݺ�
	{ //�ǹ����� ū ���� ã��������
		while (pivot >= arr[low] && low <= right)
			low++; //low�� ����������

		while (pivot <= arr[high] && high >= (left + 1))
			high--;

		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);//�ǹ��� high�� ������ ��ȯ
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