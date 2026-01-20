#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vll vector<ll>
#define endl "\n"
/*-----------------------------------------------------------------------------------------------------------------------------*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
/*-----------------------------------------------------------------------------------------------------------------------------*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, q;
    cin >> n >> q;
    vll v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
 
    vector<vll> dp(n, vll(31, 1e9 + 5));
    for (int i = 0; i < n; i++) {
        dp[i][0] = v[i]; 
    }
 
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <=n; i++) {
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
 
  
    auto fun = [&](ll l, ll r) -> ll {
        int j = log2(r-l+1);
        return min(dp[l][j], dp[r - (1 << j) + 1][j]);
    };
 
   
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << fun(l - 1, r - 1) << endl;
    }
 
    return 0;
}