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
int main(){
ll t;
cin>>t;
//t=1;
cout<<t<<" ";
while(t!=1){
 if(t&1){
    t*=3;
    t++;
    cout<<t<<" ";}
 else {
    t/=2;
    cout<<t<<" ";
 }
 
 
  }
  cout<<endl;
}