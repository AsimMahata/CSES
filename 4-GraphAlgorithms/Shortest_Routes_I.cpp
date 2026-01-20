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
    vector<vector<pair<ll,ll>>> g(n);
    for(int i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        --u,--v;
        g[u].pb({v,w});
    }
    vector<ll> dis(n,1e15);
    dis[0]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        if(x.ff>dis[x.ss])continue;
        for(auto &p: g[x.ss]){
            if(dis[p.ff]>dis[x.ss]+p.ss){
                dis[p.ff]=dis[x.ss]+p.ss;
                pq.push({dis[p.ff],p.ff});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dis[i]==1e15)dis[i]=-1;
        cout<<dis[i]<<" ";
    }
}