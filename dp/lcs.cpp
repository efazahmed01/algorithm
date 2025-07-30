#include <bits/stdc++.h>
using namespace std;

string lcs(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Fill DP table
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Trace back to get the LCS string
    int i = n, j = m;
    string lcs = "";
    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            lcs += a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end()); // since we built it backwards
    return lcs;
}

int main()
{
    string a, b;
    cin >> a >> b;
    string lcs = lcs(a, b);
    cout << "LCS: " << lcs << endl;
    cout << "Length: " << lcs.size() << endl;
}
