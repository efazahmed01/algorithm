#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n-1; i++)
    {
        int swp = 1;
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1]) 
            {
                swap(a[j],a[j+1]);
                swp = 0;
            }
        }
        if(swp) break;
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
