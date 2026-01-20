#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define vi vector<int>
#define vs vector<string>
#define ff first
#define ss second
#define vc vector<char>
#define vb vector<bool>
#define sz(x) (x).size()
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define all(x) (x).begin(), (x).end()
#define endl "\n"
//#define ll int
#define setbits(x) __builtin_popcount(x)
#define read(x) int x; cin>>x
const int mod = 1e9 + 7;
void print(auto &x){
    cout<<x<<"\n";
}
 
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
 
bool vis[1005][1005]; // Corrected size
 
void dfs(ll i, ll j, ll n, ll m, vector<vector<char>> &v) {
    vis[i][j] = 1;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    for(int k = 0; k < 4; k++) {
        ll ni = i + dx[k];
        ll nj = j + dy[k];
        
        if(ni >= 0 && nj >= 0 && ni < n && nj < m) {
            if(!vis[ni][nj] && v[ni][nj] != '#') {
                dfs(ni, nj, n, m, v);
            }
        }
    }
}
 
int main() {
    ll t;
    //cin >> t;
    t = 1;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<char>> v(n, vector<char> (m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
            }   
        }
        
        memset(vis, 0, sizeof(vis)); // Initialize the visited array
 
        ll ct = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && v[i][j] != '#') { // Add condition to check non-wall cells
                    ct++;
                    dfs(i, j, n, m, v);
                }
            }   
        }
        cout << ct << endl;
    }
}