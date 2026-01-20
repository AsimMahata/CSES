#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
// #pragma GCC target("popcnt") uncomment if TLE
 
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
const ll mx=3000;
bitset<mx> x[mx];
inline int intersection(int i, int j){
    return (x[i]&x[j]).count();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        x[i]=bitset<mx>(s);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll c=intersection(i,j);
            ans+=(c*(c-1))/2;
        }
    }
    cout<<ans<<endl;
}