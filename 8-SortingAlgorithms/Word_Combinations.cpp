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
ll ct=0;
ll tr[1000005][26];
ll ep[1000006];
void insert(string s){
    ll curr=0;
    for(char &c: s){
        if(tr[curr][c-'a']==0)tr[curr][c-'a']=++ct;
        curr=tr[curr][c-'a'];
    }
    ep[curr]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    ll n=sz(s);
    ll k;cin>>k;
    
    for(int i=0;i<k;i++){
        string a;cin>>a;
        if(sz(a)<=n)insert(a);
    }
    vector<ll> dp(n+1,0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        ll curr=0;
        for(int j=i;j<n;j++){
            if(tr[curr][s[j]-'a']==0)break;
            curr=tr[curr][s[j]-'a'];
            if(ep[curr]){
                dp[i]+=dp[j+1];
                dp[i]%=mod;
            }
        }
    }
 
 
    cout<<dp[0]<<endl;
}