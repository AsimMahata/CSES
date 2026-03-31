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

    ll n,m;cin>>n>>m;
    vector<ll> h(n),t(m);
    multiset<ll> ms;
    
    for(int i=0;i<n;i++){
        cin>>h[i];
        ms.insert(-h[i]);
    }
    ll mx = 0;
    for(int i=0;i<m;i++){
        cin>>t[i];
        if(mx<=-t[i]){
            cout<<-1<<endl;
            continue;
        }
        auto it = lower_bound(ms.begin(),ms.end(),-t[i]);
        if(it!=ms.end()){
            cout<<-1*(*it)<<endl;
            ms.erase(it);
        }else{
            cout<<-1<<endl;
            mx= min (mx,-t[i]);
        }
    }

}
