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
//                               << SOLVE HERE >>
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
ll s=-1;
const ll mx=1e5+5;
vector<ll> adj[mx];
ll vis[mx];
vector<ll> ans;
void dfs2(ll x,ll p){
    vis[x]=1;
    for(auto &y : adj[x]){
        if(vis[y] && y!=p){
          
            s=x;
            return;
        }
        if(!vis[y])dfs2(y,x);
    }
}
void dfs(ll x,ll p){
    vis[x]=1;
    if(s==-1)return;
    ans.pb(x);
    for(auto &y : adj[x]){
        if(s==-1)return;
        if(vis[y] && y==s && y!=p){
        cout<<sz(ans)+1<<endl;
        cout<<x+1<<" ";
        for(auto &i : ans)cout<<i+1<<" ";
        s=-1;
        continue;
        return;
        }
        if(!vis[y])dfs(y,x);
        }
    ans.pop_back();
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;cin>>n>>m;
    
    while(m--){
        ll x,y;cin>>x>>y;
        --x,--y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i=0;i<n;i++)vis[i]=0;
    for(int i=0;i<n;i++){
        //debug(i,vis[i]);
        if(!vis[i] && s==-1)dfs2(i,-1);
        //debug(i,vis[i],s);
    }
    for(int i=0;i<n;i++)vis[i]=0;
    // debug(s);
    if(s==-1)cout<<"IMPOSSIBLE"<<endl;
    else dfs(s,-1);
}