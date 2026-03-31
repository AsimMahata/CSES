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
const ll inf = 1e18;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k;cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> g(n);
    for(int i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        --u,--v;
        g[u].push_back({v,w});
    }
    vector<vector<ll>> dis(n);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [d,u] = pq.top();
        // debug(u,d);
        pq.pop();
        if(dis[u].size()>k)continue;
        dis[u].push_back(d);
        if(u==n-1 && dis[u].size()==k)break;
        for(auto &[v,w]:g[u]){
            // debug(u,v,w,w+d);
            // debug(w+d,v);
            pq.push({w+d,v});
        }
        // debug(dis);
        // debug(pq.top());
    }
    for(auto &x:dis[n-1])cout<<x<<" ";

}
