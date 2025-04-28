#include<bits/stdc++.h>
using namespace std;
int print(int arr[],int idx,int s,int sum,int n)
{
    if(idx >= n)
    {
        if(s == sum)
        {
            return 1;
        }
        return 0;
    }
    s+=arr[idx];
    int l = print(arr,idx+1,s,sum,n);
    s-=arr[idx];
    int r = print(arr,idx+1,s,sum,n);

    return l+r;
}
int main()
{
    int n,sum;
    cin >> n >> sum;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << print(arr,0,0,sum,n) << endl;
}
