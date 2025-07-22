#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &v, vector<int> &wt, int w, int n, vector<vector<int>> &dp)
{
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= w; j++) dp[0][j] = 0;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            int ww = wt[i-1];
            int vv = v[i-1];
            
            if(ww <= j)
            {
                //include
                int ans1 = vv + dp[i-1][j-ww];
                //exclude
                int ans2 = dp[i-1][j];
                
                dp[i][j] = max(ans1, ans2);
            }
            else
            {
                //exclude
                dp[i][j] = dp[i-1][j];
                
            }
        }
    }
    return dp[n][w];
}

int main()
{
    int n,w; cin >> n >> w;
    vector<int> v(n),wt(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> wt[i];
    vector<vector<int>>dp(n+1, vector<int> (w+1,-1));
    cout << knapsack(v,wt,w,n,dp) << endl;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            cout << dp[i][j] << '\t';
        }
        cout << endl;
    }
}
