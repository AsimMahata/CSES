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
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
   
    ll n,x;cin>>n>>x;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        v[i]={x,i};
    }
    sort(all(v));
    int i=0,j=n-1;
    bool f=false;
    ll l=0,r=n-1;
    while(i<j){
        
        if(v[i].ff+v[j].ff<x)i++;
        else if(v[i].ff+v[j].ff>x)j--;
        else{
            f=true;
            l=v[i].ss;
            r=v[j].ss;
            break;
        }
    }
    if(!f){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
 
    cout<<l+1<<" "<<r+1<<endl;
    
}