#include <bits/stdc++.h>
using namespace std;

bool targetSubset(vector<int> &arr, int target, int n, vector<vector<bool>> &dp)
{
    for (int i = 0; i <= n; i++) dp[i][0] = true;   // Sum 0 is always possible
    for (int j = 1; j <= target; j++) dp[0][j] = false; // No sum possible with 0 items (except 0)

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            int curr = arr[i - 1];
            if(curr <= j)
            {
                // include or exclude
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - curr];
            }
            else
            {
                // exclude only
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target];
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    bool possible = targetSubset(arr, target, n, dp);

    cout << (possible ? "YES" : "NO") << endl;

    // Print DP table (optional)
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            cout << dp[i][j] << '\t';
        }
        cout << endl;
    }
}
