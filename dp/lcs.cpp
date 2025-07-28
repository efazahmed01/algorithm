#include<bits/stdc++.h>
using namespace std;

int lcs(string a, string b)
{
    int n = a.size();
    int m = b.size();
    int dp[n+1][m+1];
    for(int i = 0 ; i < n; i++)
    {
        dp[i][0] = 0;
    }
    
    for(int i = 0; i < m; i++) dp[0][i] = 0;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            //if_same hole len 1 bare r size decrese by 1:
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            //same na hole
            else 
            {
                //case1:
                int ans1 = dp[i-1][j];
                //case2:
                int ans2 = dp[i][j-1];
                dp[i][j] = max(ans1,ans2);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string a,b; cin >> a >> b;
    cout << lcs(a,b) << endl;
}
