#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;
 
//                               << SOLVE HERE >>
const int N = 1e5+5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;cin>>n;
    vector<ll> a(n);
    bitset<N> ps;
    ps.set(0);
    for(auto &x:a){
        cin>>x;
        ps|=ps<<x;
    }
    ll ans = ps.count();
    cout<<ans-1<<endl;
    for(int i=1;i<N;i++){
        if(ps.test(i))cout<<i<<" ";
    }
}