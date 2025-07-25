#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<vector<int>> &v, int wt, int n)
{
    int dp[n+1][wt+1];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= wt; j++)
            dp[i][j] = -1;

    dp[0][0] = 0; 

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= wt; j++)
        {
            if(dp[i-1][j] != -1) 
            {
                for(auto x : v[i-1])
                {
                    if(j <= x)
                        dp[i][j] = max(dp[i][j+x], dp[i-1][j] + x);
                }
            }
        }
    }

    int ans = -1;
    for(int j = 0; j <= wt; j++)
        ans = max(ans, dp[n][j]);
        
    // for(int i = 0; i <= n; i++)
    // {
    //     for(int j = 0; j <= wt; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return ans;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int wt; cin >> wt;
        int n; cin >> n;
        vector<vector<int>> v(n); 

        for(int i = 0; i < n; i++)
        {
            int sz ; cin >> sz;
            for(int j = 0; j < sz; j++)
            {
                int x; cin >> x;
                v[i].push_back(x); 
            }    
        }

        int res = knapsack(v, wt, n);
        if(res == -1)
            cout << "no solution\n";
        else
            cout << res << endl;
    }
}

//problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2445
