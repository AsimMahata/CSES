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
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n,q;cin>>n>>q;
    vector<vll> anc(n+1,vll(25,-1));
    vector<vll> g(n+1);
    for(int i=2;i<=n;i++){
        ll x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    vll dep(n+1,0);
    function<void(ll,ll,ll)> dfs=[&](ll p,ll x,ll d)->void{
        dep[x]=d;
        anc[x][0]=p;
        for(int j=1;j<25;j++){
            if(anc[x][j-1]!=-1)anc[x][j]=anc[anc[x][j-1]][j-1];
        }
        for(auto &y:g[x]){
            if(y!=p)dfs(x,y,d+1);
        }
    };
    dfs(-1,1,1);
    function<ll(ll,ll)> fun=[&](ll x,ll y)->ll{
        if(dep[x]>dep[y])swap(x,y);
        ll d=dep[y]-dep[x];
        for(int j=24;j>=0;j--){
            if(d&(1<<j))y=anc[y][j];
        }
        if(x==y)return x;
        for(int j=24;j>=0;j--){
            if(anc[x][j]!=anc[y][j]){
                x=anc[x][j];
                y=anc[y][j];
            }
        }
        return anc[x][0];
    };
    while(q--){
        ll x,y;cin>>x>>y;
        ll p=fun(x,y);
        
        ll ans=dep[p]-dep[x]+dep[p]-dep[y];
        cout<<-ans<<endl;
    }
}