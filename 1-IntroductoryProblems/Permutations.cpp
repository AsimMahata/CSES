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
    if(n==1)cout<<1<<endl;
    else if(n<=3)cout<<"NO SOLUTION"<<endl;
    else{
        vector<ll> v;
        for(int i=2;i<=n;i+=2)v.pb(i);
        for(int i=1;i<=n;i+=2)v.pb(i);
        for(auto &i : v)cout<<i<<" ";
        cout<<endl;
    }
}