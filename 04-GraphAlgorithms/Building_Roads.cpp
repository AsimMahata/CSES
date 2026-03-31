#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;

//                               << SOLVE HERE >>
vector<vector<ll>> g;
vector<ll> vis;
void dfs(ll u){
    vis[u]=1;
    for(auto &v:g[u]){
        if(!vis[v])dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;cin>>n>>m;
    g.assign(n,{});
    vis.assign(n,0);
    for(int i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> comp;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
            comp.push_back(i+1);
        }
    }
    cout<<comp.size()-1<<endl;
    for(int i=1;i<comp.size();i++){
        cout<<comp[i-1]<<" "<<comp[i]<<endl;
    }
}
