#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;

//                               << SOLVE HERE >>
const ll inf = 1e18;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;cin>>n>>m;
    vector<vector<ll>> g(n);
    vector<ll> indeg(n);
    for(int i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        --u,--v;
        g[u].push_back(v);
        indeg[v]++;
    }
    queue<ll> q;
    for(int i=0;i<n;i++){
        if(!indeg[i])q.push(i);
    }
    vector<ll> dp(n,0);
    dp[0]=1;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto &v:g[u]){
            indeg[v]--;
            dp[v] = (dp[v]+dp[u])%mod;
            if(!indeg[v])q.push(v);
        }
    }
    cout<<dp.back()<<endl;
}
