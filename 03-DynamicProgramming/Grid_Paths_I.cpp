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
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
       ll n;
       cin>>n;
       ll dp[n+1][n+1];
        vector<vector<char>> v(n,vector<char> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            cin>>v[i][j];
            dp[i][j]=0;
            }
        }
  
    dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='*')continue;
                dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
                dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
            }
        }
    dp[n-1][n-1]=(v[n-1][n-1]=='*')?0:dp[n-1][n-1];
  cout<<dp[n-1][n-1]<<endl;
}