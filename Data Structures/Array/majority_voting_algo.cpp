/**
 * https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
 *
 * First find the right element by comparing current array element with the cadidate value
 * Then recheck if it's the right candidate otherwise return -1
 *
 * Time = O(n)
 * Space = O(1)
 */

#include <bits/stdc++.h>

using namespace std;

int findMajority(int arr[], int n)
{
    int votes = 0, candidate = -1;
    for (int i = 0; i < n; i++)
    {
        if (votes == 0)
        {
            candidate = arr[i];
            votes = 1;
        }
        else
        {
            if (arr[i] == candidate)
                votes++;
            else
                votes--;
        }
    }
    int total = count(arr, arr + n, candidate);
    if (total > n / 2)
        return candidate;
    else
        return -1;
}

int main(void)
{
    // int arr[] = {1, 1, 1, 1, 2, 3, 4};
    int arr[] = {1, 2, 1, 3, 1, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " The majority element is : " << findMajority(arr, n);
    return 0;
}
