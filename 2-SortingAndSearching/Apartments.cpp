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
 
    ll n,m,k;cin>>n>>m>>k;
    multiset<ll> a,b;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        a.insert(x);
    }
    for(int i=0;i<m;i++){
        ll x;cin>>x;
        b.insert(x);
    }
    ll cnt=0;
    for(auto &x:a){
        auto it = b.lower_bound(x-k);
        if(*it>=x-k && *it<=x+k){
            cnt++;
            b.erase(it);
        }
    }
    cout<<cnt<<endl;
}