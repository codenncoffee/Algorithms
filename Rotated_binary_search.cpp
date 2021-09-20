#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define endl "\n"
#define SIZE 1000001
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (high + low) / 2;
    if (key == arr[mid])
    {
        return mid;
    }
    if (key > arr[mid])
    {
        return binarySearch(arr, mid + 1, high, key);
    }
    else
    {
        return binarySearch(arr, low, mid - 1, key);
    }
}
int findPivot(int arr[], int low, int high)
{
    if (high < low)
    {
        return -1;
    }
    if (high == low)
    {
        return high;
    }
    int mid = (high + low) / 2;
    if (mid > low && arr[mid] < arr[mid - 1])
    {
        return mid - 1;
    }
    if (mid < high && arr[mid] > arr[mid + 1])
    {
        return mid;
    }
    if (arr[low] >= arr[mid])
    {
        return findPivot(arr, low, mid - 1);
    }
    return findPivot(arr, mid + 1, high);
}
int pBS(int arr[], int n, int key)
{
    int pv = findPivot(arr, 0, n - 1); // finding the pivot
    if (pv == -1)
    {
        return binarySearch(arr, 0, n - 1, key);
    }
    if (arr[0] <= key)
    { // 3,4,5,1,2
        return binarySearch(arr, 0, pv, key);
    }
    else
    {
        return binarySearch(arr, pv, n - 1, key);
    }
}
void solve()
{
    int arr[] = {3, 4, 5, 1, 2};
    int n = 5;
    int key = 3;
    cout << pBS(arr, n, key);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //cout << "Case m#" << i << ":" << endl;
        solve();
    }
    return 0;
}
