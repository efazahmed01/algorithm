#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n-1; i++)
    {
        int si = i;
        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[si])
                si = j;
        }
        swap(a[si],a[i]);
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
