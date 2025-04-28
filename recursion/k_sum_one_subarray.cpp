#include<bits/stdc++.h>
using namespace std;
bool print(int arr[],int idx,vector<int> &v,int s,int sum,int n)
{
    if(idx >= n)
    {
        if(s == sum)
        {
            for(auto it: v) cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    v.push_back(arr[idx]);
    s+=arr[idx];
    if(print(arr,idx+1,v,s,sum,n))
    {
        return true;
    }
    s-=arr[idx];
    v.pop_back();
    if(print(arr,idx+1,v,s,sum,n))
    {
        return true;
    }
    return false;
}
int main()
{
    int n,sum;
    cin >> n >> sum;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> v;
    
    print(arr,0,v,0,sum,n);
}
