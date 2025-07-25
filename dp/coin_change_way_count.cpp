#include<bits/stdc++.h>
using namespace std;

int coin_change(vector<int> &coins,int total,int n, vector<vector<int>> &dp)
{
    for(int j = 0; j <= total; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= total; j++)
        {

            if(coins[i-1] <= j)
            {
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }
            else
            {
                //exclude
                dp[i][j] = dp[i-1][j];
                
            }
        }
    }
    return dp[n][total];
}

int main()
{
    int n,total; cin >> n >> total;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    vector<vector<int>>dp(n+1, vector<int> (total+1));
    cout << coin_change(coins,total,n,dp) << endl;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= total; j++)
        {
            cout << dp[i][j] << '\t';
        }
        cout << endl;
    }
}
