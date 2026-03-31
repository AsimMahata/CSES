#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;
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
vector<vector<pair<ll,ll>>> g[2];
vector<vector<ll>> dis;
vector<vector<ll>> vis;
// vector<ll> vis[2];
void djk(ll st){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,st});
    while (!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(dis[!st][u]<d)continue;
        dis[!st][u]=d;
        for(auto &e:g[!st][u]){
            ll v = e.first;
            ll w = e.second;
            if(dis[!st][u]+w<dis[!st][v]){
                dis[!st][v]=dis[!st][u]+w;
                pq.push({dis[!st][v],v});
            }
        }
    } 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;cin>>n>>m;
    g[0].assign(n,{});
    g[1].assign(n,{});
    vector<vector<ll>> edges;
    for(int i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        --u,--v;
        g[1][u].push_back({v,w});
        g[0][v].push_back({u,w});
        edges.push_back({u,v,w});
    }
    dis.assign(2,vector<ll>(n,1e18));
    vis.assign(2,vector<ll>(n,0));
    djk(0);
    djk(n-1);
    ll ans = 1e18;
    // debug(dis);
    for(auto &e:edges){
        ll u=e[0];
        ll v=e[1];
        ll w=e[2];
        // ans = min(ans, dis[0][u]+dis[1][v]+w/2);
        ans = min(ans, dis[0][v]+dis[1][u]+w/2);
    }
    cout<<ans<<endl;
}
