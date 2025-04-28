#include<bits/stdc++.h>
using namespace std;
int print(int arr[],int idx,vector<int> &v,int s,int sum,int n)
{
    if(idx >= n)
    {
        if(s == sum)
        {
            return 1;
        }
        return 0;
    }
    v.push_back(arr[idx]);
    s+=arr[idx];
    int l = print(arr,idx+1,v,s,sum,n);
    s-=arr[idx];
    v.pop_back();
    int r = print(arr,idx+1,v,s,sum,n);

    return l+r;
}
int main()
{
    int n,sum;
    cin >> n >> sum;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> v;
    
    cout << print(arr,0,v,0,sum,n) << endl;
}
