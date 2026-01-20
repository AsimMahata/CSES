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
    ll q;cin>>q;
    vll v(n);
    vll x(n+1,0);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)x[i]=x[i-1]^v[i-1];
    while(q--){
        ll l,r;cin>>l>>r;
        cout<<(ll)(x[l-1]^x[r])<<endl;
    }
   
}