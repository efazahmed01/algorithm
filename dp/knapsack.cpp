#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &v, vector<int> &wt, int w, int n, vector<vector<int>> &dp)
{
    if(w == 0 || n == 0) return 0;
    
    if(dp[n][w] != -1) return dp[n][w];
    
    if(w >= wt[n-1])
    {
        //include
        int ans1 = v[n-1] + knapsack(v,wt,w-wt[n-1],n-1,dp);
        //exclude
        int ans2 = knapsack(v,wt,w,n-1,dp);
        
        dp[n][w] = max(ans1,ans2);
        return dp[n][w];
    }
    else
    {
        //exclude
        dp[n][w] = knapsack(v,wt,w,n-1,dp);
        return dp[n][w];
    }
}

int main()
{
    int n,w; cin >> n >> w;
    vector<int> v(n),wt(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> wt[i];
    vector<vector<int>>dp(n+1, vector<int> (w+1,-1));
    cout << knapsack(v,wt,w,n,dp) << endl;;
}
