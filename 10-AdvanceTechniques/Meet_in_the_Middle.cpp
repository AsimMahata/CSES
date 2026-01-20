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
//                              << SOLVE HERE >>
 
int main()
{
 
    ll n,x;cin>>n>>x;
    vector<ll> v(n);
    unordered_map<ll,ll> mp;
    for(int i=0;i<n;i++)cin>>v[i];
    ll n1=1<<(n/2);
    ll n2=1<<((n+1)/2);
    mp.reserve(1 << (n / 2));
    for(int i=0;i<n1;i++){
        ll a=0;
        for(int j=0;j<n/2;j++){
            if(i&(1<<j)){
                a+=v[j];
            }
        }
     if(a<=x)mp[a]++;
    }
    ll ans=0;
    for(int i=0;i<n2;i++){
        ll a=0;
        for(int j=0;j<(n+1)/2;j++){
            if(i&(1<<j)){
                a+=v[n/2+j];
            }
        }
         if(mp.find(x-a)!= mp.end())
            ans += mp[x-a];
    }
    cout<<ans<<endl;
}