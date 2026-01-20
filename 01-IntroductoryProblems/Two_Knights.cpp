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
    ll n;cin>>n;
    vector<ll> v={0,6,28,96,252,550};
    for(int i=1;i<=n;i++){
        if(i<=6)cout<<v[i-1]<<endl;
        else{
            ll n2=i*i;
            ll ans=0;
            ans=4*(n2-3)+8*(n2-4)+(i-4)*4*(n2-5+n2-7)+(i-4)*(i-4)*(n2-9)+4*(n2-5);
            ans/=2;
            cout<<ans<<endl;
        }
    }
}