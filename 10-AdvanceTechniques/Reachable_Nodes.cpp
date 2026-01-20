#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
// #pragma GCC target("popcnt")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
// uncomment if TLE
 
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define ff first
#define ss second
#define sz(x) (x).size()
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define setbits(x) __builtin_popcount(x)
const int mod = 1e9 + 7;
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
//                               << SOLVE HERE >>
const int N=5e4+1;
bitset<N> bt[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;cin>>n>>m;
    vector<vll> g(n);
    for(int i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        --x,--y;
        g[x].pb(y);
    }
    vll vis(n,0);
    function<void(ll)> dfs=[&](ll x)->void{
        bt[x].set(x);
        vis[x]=1;
        for(auto &y:g[x]){
            if(!vis[y]){dfs(y);
            }
            bt[x]|=bt[y];
            //debug(x,y,ans[y]);
        }
        
        //debug(x,a);
    };
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i);
    }
    for(int i=0;i<n;i++)cout<<bt[i].count()<<" ";
}