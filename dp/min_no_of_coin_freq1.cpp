#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX

ll coin(vector<ll> &coins, ll target) {
    vector<ll> dp(target + 1, INF);
    dp[0] = 0;

    for (ll coin : coins)
       {
        for (ll j = target; j >= coin; j--) 
        {
            if (dp[j - coin] != INF)
                dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    return dp[target] == INF ? -1 : dp[target];
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &it : v) cin >> it;

    cout << coin(v, k) << endl;
}
