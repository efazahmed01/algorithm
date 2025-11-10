#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'

ll mySqrt(ll x) {
    if(x == 0) return x;
    long long lo = 1,hi = x;
    while(lo <= hi){
        long long mid = lo + (hi-lo)/2;
        if(mid == x/mid) return mid; 
        if(mid >= x/mid) hi = mid-1;
        else lo = mid+1;

    }
    // hi is the last mid 
    // where mid*mid <= x
    return hi;
}


void solve() {
    ll x; cin >> x;
    cout << mySqrt(x) << endl;
}

int main(){
    int t =1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
