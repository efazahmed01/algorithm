#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll coin(vector<ll> &c, ll t)
{
    vector<ll> dp(t+1,LLONG_MAX);
    dp[0] = 0;
    for(int i = 1; i <= t; i++)
    {
        for(int cn : c)
        {
            if(i >= cn && dp[i-cn]!= LLONG_MAX)
                dp[i] = min(dp[i],dp[i-cn]+1);
        }
    }
    return dp[t] == LLONG_MAX ? -1 : dp[t];
}

int main()
{
    ll n,k; cin >> n >> k;
    vector<ll> v(n);
    for(auto &it:v) cin >> it;
    cout << coin(v,k) << endl;
}
