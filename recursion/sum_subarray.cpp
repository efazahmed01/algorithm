#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int idx,vector<int> &v,int s,int sum,int n)
{
    if(idx >= n)
    {
        if(s == sum)
        {
            for(auto it: v) cout << it << " ";
            cout << endl;
        }
        return;
    }
    v.push_back(arr[idx]);
    s+=arr[idx];
    print(arr,idx+1,v,s,sum,n);
    s-=arr[idx];
    v.pop_back();
    print(arr,idx+1,v,s,sum,n);
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
