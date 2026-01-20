#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
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
 
 
const int N = 1e6+7;
int fact[N],invfact[N];
 
ll exp(ll a,ll b){
    
    ll res=1;
    while(b){
        if(b&1){
            res*=a;
            res%=mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    
    return res;
}
ll ncr(ll n,ll r){
    if(n==r || r==0)return 1;
    if(r==1)return n%mod;
    ll ncr = 1ll*fact[n]*invfact[r];
    ncr%=mod;
    
    ncr=(ncr*invfact[n-r])%mod;
    
    return ncr;
}
ll inv(ll x){
    return exp(x,mod-2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0]=1;
    for(ll i=1;i<N;i++){
        fact[i]=(1ll*fact[i-1]*i)%mod;
    }
    invfact[N-1]=inv(fact[N-1]);
    
    for(ll i=N-2;i>=0;i--){
        invfact[i]=(1ll*invfact[i+1]*(i+1))%mod;
    }
  
        string s;cin>>s;
        vector<ll> f(26,0);
        // debug(s);
        for(auto c:s)f[c-'a']++;
        ll n= s.size();
        ll ans=fact[n];
        // debug(f);
        for(auto &x:f){
            ans=(ans*invfact[x])%mod;
        }
        cout<<ans<<endl;
    
}