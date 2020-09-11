#include <stdio.h>

int BSearchRecur(int arr[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;

	mid = (first + last) / 2;
	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return BSearchRecur(arr, first, mid - 1, target);
	else
		return BSearchRecur(arr, mid + 1, last, target);
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°ÙÀúÀå ÀÎµ¦½º: %d \n", idx);

	return 0;
}