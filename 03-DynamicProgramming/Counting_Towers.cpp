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
    ll mx=1e6+5;
    vector<vll> dp(mx,vll(2,0));
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;cin>>n;
        dp[n][0]=1;
        dp[n][1]=1;
        for(int i=n-1;i>=0;i--){
            dp[i][0]=(2ll*dp[i+1][0]+dp[i+1][1])%mod;
            dp[i][1]=(4ll*dp[i+1][1]+dp[i+1][0])%mod;
        }
        ll ans=dp[1][0]+dp[1][1];
        cout<<ans%mod<<endl;       
    }
}