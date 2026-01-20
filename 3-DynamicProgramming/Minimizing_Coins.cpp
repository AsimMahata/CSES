#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;
 
//                               << SOLVE HERE >>
const int N=1e6+2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,s;cin>>n>>s;
    vector<ll> dp(N,1e18);
    dp[0]=0;
    vector<ll> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
        dp[c[i]]=1;
    }
    sort(c.begin(),c.end());
    for(int i=1;i<=s;i++){
        for(auto &coin:c){
            if(coin<=i)dp[i]=min(dp[i],dp[i-coin]+1);
            else break;
        }
    }
    cout<<(dp[s]>=1e18?-1:dp[s]);
}