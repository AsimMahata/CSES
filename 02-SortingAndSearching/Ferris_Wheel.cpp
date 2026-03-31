#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;

//                               << SOLVE HERE >>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;cin>>n;
    ll x;cin>>x;
    vector<ll> a(n);
    for(auto &e:a)cin>>e;
    sort(a.begin(),a.end());
    ll ans =0;
    ll l=0;
    ll r =n-1;
    while(l<=r){
        if(a[l]+a[r]<=x){
            l++;r--;
        }else{
            r--;
        }
        ans++;
    }
    cout<<ans<<endl;
    
}
