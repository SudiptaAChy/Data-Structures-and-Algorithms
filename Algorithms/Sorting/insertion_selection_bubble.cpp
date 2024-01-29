#include <bits/stdc++.h>
#define pb push_back
#define sf scanf
#define pf printf
#define inf 1000000000
#define pii pair<ll, ll>
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll long long
const int N = 2e5 + 5;
void swap(int& a, int& b) {
    if (&a != &b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
}
/**
 * select the minimum element and swap with the
 * very first element of the array
 * -> min element comes at first
*/
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

/**
 * check for adjacent elements
 * if current elem greater than next elem just swap
 * -> max element comes at end
*/
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // array is already sorted
    }
}

/**
 * like sorting playing card
 * select an elem and place it to it's appropiate position
 * from the prev elemts of current elem
 * best case o(n)
 * if array size of small (<100) and assume that array is almost sorted we can use this blindly
*/
void inserationSort(int* arr, int n) {
    for (int i = 1;i < n;i++) {
        int item = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > item)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = item;
    }
}

void slv()
{
    int arr[] = { 2,6,8,1,4,3,6,0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    inserationSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    // t = 1;
    for (int cas = 1; cas <= t; cas++)
    {
        // printf("Case %d: ", cas);
        slv();
    }
    return 0;
}