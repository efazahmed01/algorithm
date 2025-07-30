#include<bits/stdc++.h>
using namespace std;

string lcs_string(string a, string b)
{
    int a_size = a.size();
    int b_size = b.size();
    
    int dp[a_size+1][b_size+1];

    // Initialize first row and column
    for(int i = 0 ; i <= a_size; i++) dp[i][0] = 0;
    for(int i = 0; i <= b_size; i++) dp[0][i] = 0;
    
    int ans = 0;
    int last_idx = 0;

    // Fill DP table
    for(int i = 1; i <= a_size; i++)
    {
        for(int j = 1; j <= b_size; j++)
        {
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(ans < dp[i][j])
                {
                    ans = dp[i][j];
                    last_idx = i; // ending index in 'a'
                }
            }
            else dp[i][j] = 0;
        }
    }

    // Extract substring from a
    return a.substr(last_idx - ans, ans);
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << lcs_string(a, b) << endl;
}
