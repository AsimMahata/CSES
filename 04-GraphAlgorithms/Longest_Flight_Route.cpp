#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m; cin>>n>>m;
    vector<vector<ll>> g(n);
    vector<ll> indeg(n,0);

    for(int i=0;i<m;i++){
        ll u,v; cin>>u>>v;
        --u,--v;
        g[u].push_back(v);
        indeg[v]++;
    }

    queue<ll> q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0) q.push(i);
    }

    vector<ll> topo;
    while(!q.empty()){
        ll u=q.front(); q.pop();
        topo.push_back(u);
        for(auto &v:g[u]){
            if(--indeg[v]==0) q.push(v);
        }
    }

    vector<ll> dp(n,-1e18), par(n,-1);
    dp[0]=0;

    for(auto &u:topo){
        if(dp[u]<0) continue;
        for(auto &v:g[u]){
            if(dp[u]+1 > dp[v]){
                dp[v]=dp[u]+1;
                par[v]=u;
            }
        }
    }

    if(dp[n-1]<0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<ll> path;
    ll curr=n-1;
    while(curr!=-1){
        path.push_back(curr);
        curr=par[curr];
    }

    reverse(path.begin(),path.end());

    cout<<path.size()<<endl;
    for(auto &x:path) cout<<x+1<<" ";
}