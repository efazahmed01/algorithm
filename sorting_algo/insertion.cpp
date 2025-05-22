#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 1; i < n; i++)
    {
        int j = i-1;
        int v = a[i];
        while(j >= 0 && a[j] > v)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
