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
const ll mx=2e5+5;
ll a[mx];
ll seg[4*mx];
ll n;
void update(ll k,ll u,ll i=0,ll l=0,ll r=n-1){
    if(l==r && l==k){
        seg[i]=u;
        return;
    }
    if(l>k)return;
    if(r<k)return;
    ll mid=(l+r)>>1;
    update(k,u,2*i+1,l,mid);
    update(k,u,2*i+2,mid+1,r);
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
ll fun(ll l, ll r , ll i=0,ll left=0,ll right=n-1){
    if(left>=l && right<=r)return seg[i];
    if(r<left || l>right)return 0ll;
    ll mid=(left+right)>>1;
    return fun(l,r,2*i+1,left,mid)+fun(l,r,2*i+2,mid+1,right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)update(i,a[i]);
    while(q--){
        ll t;cin>>t;
        if(t==1){
            ll k,u;cin>>k>>u;--k;
            update(k,u);
        }else{
            ll l,r;cin>>l>>r;--l,--r;
            cout<<fun(l,r)<<endl;
        }
    }
}