#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int lo, int hi) 
{
    int pivot = v[lo];
    int l = lo + 1;
    int h = hi;

    while(l <= h) 
    {
        while(l <= hi && v[l] <= pivot) l++;
        while(v[h] > pivot) h--;
        if(l < h) swap(v[l], v[h]);
    }
    swap(v[lo], v[h]);
    return h;
}

void Quicksort(vector<int> &v, int lo, int hi) 
{
    if(lo < hi) 
    {
        int part = partition(v, lo, hi);
        Quicksort(v, lo, part - 1);
        Quicksort(v, part + 1, hi);
    }
}

int main() 
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it: v) cin >> it;
    Quicksort(v, 0, n - 1);
    for(auto it: v) cout << it << " ";
}
