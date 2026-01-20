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
ll fun(ll n,ll k){
    if(n==1)return 1;
    if(k<=(n+1)/2){
        if(2*k>n)return (2*k)%n;
        else return 2*k;
    }
    ll t=fun(n/2,k-(n+1)/2);
    if(n%2==1)return 2*t+1;
    else return 2*t-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--)
    {
     ll n,k;cin>>n>>k;
     cout<<fun(n,k)<<endl;   
    }
}