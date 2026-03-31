#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;

//                               << SOLVE HERE >>
vector<vector<ll>> g;
vector<ll> vis,par;
void bfs(ll u){
    queue<ll> q;
    q.push(u);
    vis[0]=1;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        for(auto &y:g[x]){
            if(!vis[y]){
                par[y]=x;
                q.push(y);
                vis[y]=1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;cin>>n>>m;
    g.assign(n,{});
    vis.assign(n,0);
    par.assign(n,-1);
    for(int i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(0);
    vector<ll> path;
    ll v = n-1;
    while(v!=-1){
        path.push_back(v);
        v=par[v];
    }
    reverse(begin(path),end(path));
    if(path.size()>1){
        cout<<path.size()<<endl;
        for(auto &x:path)cout<<x+1<<" ";
        cout<<endl;
    }else cout<<"IMPOSSIBLE\n";
}
