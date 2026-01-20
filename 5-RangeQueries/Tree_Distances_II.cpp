#include <bits/stdc++.h>
using namespace std;
 
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
const int mx=2e5+5;
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
ll n;
vector<ll> adj[mx];
vector<ll> dis(mx,0);
vector<ll> a(mx,0);
void dfs(ll p,ll x){
    for(auto &y : adj[x]){
        if(y!=p){
            ll t=a[y];
            dis[y]=dis[x]+(n-t)-t;
            dfs(x,y);
        }
    }
}
ll dfs3(ll p,ll x,ll d){
    dis[0]+=d;
    ll b=1;
    for(auto &y : adj[x]){
        if(y!=p){
            b+=dfs3(x,y,d+1);
        }
    }
    a[x]=b;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        --x,--y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    dfs3(-1,0,0);
    dfs(-1,0);
    for(int i=0;i<n;i++)cout<<dis[i]<<" ";
    
}