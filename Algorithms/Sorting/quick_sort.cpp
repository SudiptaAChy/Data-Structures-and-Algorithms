/**
 * https://www.geeksforgeeks.org/quick-sort/
 * https://www.interviewbit.com/tutorial/quicksort-algorithm/#h827ske1ht0ea2fcemd1dxxl7u1ndu40q
 * https://www.youtube.com/watch?v=PmlfVdY_XjI
 * https://www.youtube.com/watch?v=kwG0C2Lv-fQ
 * https://www.youtube.com/watch?v=MbO_N_7xSD0
 *
 * Time = O(NlogN) for best/avg case; O(N^2) for worst case
 * Worst case means the array is sorted in ASC or DSC order and we are taking the last or first element as pivot
 *
 * Space = O(N) for worst case O(logN) for avg case
 */

#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int lo, int hi) // O(N)
{
    int i = lo - 1;
    for (int j = lo; j < hi; j++)
    {
        if (arr[j] < arr[hi])
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(arr[i + 1], arr[hi]);
    return i + 1;
}

void quickSort(int arr[], int lo, int hi) // O(logN)
{
    if (lo < hi)
    {
        int pivot = partition(arr, lo, hi);
        quickSort(arr, lo, pivot - 1);
        quickSort(arr, pivot + 1, hi);
    }
}

int main(void)
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
