/**
 * t.ly/JveN
 * Time = O(NlogN)
 * Space = O(N)
 */

#include <bits/stdc++.h>

using namespace std;

void merge(int *arr, int lo, int mid, int hi)
{
	int temp[hi - lo + 1];
	int i = lo, j = mid + 1, k = 0;
	while (i <= mid && j <= hi)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= hi)
		temp[k++] = arr[j++];
	for (int i = lo; i <= hi; i++)
		arr[i] = temp[i - lo];
}

void mergeSort(int *arr, int lo, int hi)
{
	if (lo < hi)
	{
		int mid = (lo + hi) / 2;
		mergeSort(arr, lo, mid);
		mergeSort(arr, mid + 1, hi);
		merge(arr, lo, mid, hi);
	}
}

int main(void)
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
