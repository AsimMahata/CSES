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
int binExp(int a, int b, int M){
          int res=1;
          while(b){
            if(b&1){
              res=(res*1LL*a)%M;
            }
            a=(a*1LL*a)%M;
            b=b>>1;
          }
          return res;
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll a,b,c;cin>>a>>b>>c;
        ll ans=binExp(b,c,mod-1);
        cout<<binExp(a,ans,mod)<<endl;
    }
}