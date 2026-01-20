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
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;cin>>n;
    vector<vector<ll>> adj(n);
    for(int i=0;i<n-1;i++){
        ll x,y;cin>>x>>y;
        --x,--y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll> dp(n,0);
    function<void(ll,ll,ll)> dfs = [&](ll x, ll p,ll d) -> void {   
    dp[x]=max(dp[x],d);
    for(ll &y : adj[x]) { 
        if(y!=p)dfs(y,x,d+1);
        }
    };
    dfs(0,-1,0);
    ll mx=max_element(all(dp))-dp.begin();
    dfs(mx,-1,0);
    mx=max_element(all(dp))-dp.begin();
    dfs(mx,-1,0);
    for(auto i :dp)cout<<i<<" ";
}