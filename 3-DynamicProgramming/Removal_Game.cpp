#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 5005;
ll dp[N][N];
ll a[N];
ll rec(ll l,ll r){
    if(l==r)return a[l];
    if(r-l==1)return max(a[l],a[r]);
    ll &ans=dp[l][r];
    if(ans!=-1e18)return ans;
    ans=max(a[l]+min(rec(l+2,r),rec(l+1,r-1)),a[r]+min(rec(l+1,r-1),rec(l,r-2)));
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)dp[i][j]=-1e18;
    }
    cout << rec(0,n-1) << endl;
}