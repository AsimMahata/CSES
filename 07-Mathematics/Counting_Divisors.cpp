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
const ll mx=1e6+5;
vector<ll> v(mx,1);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=2;i<mx;i++){
        for(int j=i;j<mx;j+=i)v[j]++;
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;cin>>n;
        cout<<v[n]<<endl;
    }
}