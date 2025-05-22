#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int st, int mid, int end) 
{
    vector<int> tmp;
    int i = st, j = mid + 1;

    while(i <= mid && j <= end) 
    {
        if (arr[i] <= arr[j]) 
        {
            tmp.push_back(arr[i]);
            i++;
        } 
        else 
        {
            tmp.push_back(arr[j]);
            j++;
        }
    }

    // Left part
    while(i <= mid) 
    {
        tmp.push_back(arr[i]);
        i++;
    }

    // Right part
    while(j <= end) 
    {
        tmp.push_back(arr[j]);
        j++;
    }

    for(int k = 0; k < tmp.size(); k++) 
    {
        arr[st + k] = tmp[k];
    }
}

void mergesort(int arr[], int st, int end) 
{
    if(st < end) 
    {
        int mid = (st + end) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main() 
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergesort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
