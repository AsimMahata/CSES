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
    
    ll n,m;cin>>n>>m;
    vector<vector<ll>> adj(n);
    while(m--){
        ll x,y;cin>>x>>y;
        --x,--y;
        adj[x].pb(y);
        adj[y].pb(x);
 
    }
    vector<ll> color(n,0);
    vector<ll> vis(n,0);
    bool f=true;
    function<void(ll,ll)> dfs = [&](ll x, ll c) -> void {
    vis[x] = 1;        
    color[x] = c;       
    for (ll &y : adj[x]) { 
        if (!vis[y]) {
            dfs(y, c ^ 1); 
            if (!f) return; 
        } else if (color[x] == color[y]) {
            f = false; 
            return;
        }
    }
};
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i,0);
    }
    if(f){
        for(auto &c: color)cout<<c+1<<" ";
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}