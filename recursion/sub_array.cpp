#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int idx,vector<int> &v,int n)
{
    if(idx >= n)
    {
        for(auto it: v) cout << it << " ";
        cout << endl;
        return;
    }
    v.push_back(arr[idx]);
    print(arr,idx+1,v,n);
    v.pop_back();
    print(arr,idx+1,v,n);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> v;
    
    print(arr,0,v,n);
}
