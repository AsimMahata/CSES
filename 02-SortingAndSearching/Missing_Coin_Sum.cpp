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
    ll ct=0;
    vll v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(all(v));
    for(int i=0;i<n;i++){
        ll x=v[i];
        if(ct+1>=x){
            ct+=x;
        }else{
            cout<<ct+1<<endl;
            return 0;
        }
    }
    cout<<ct+1<<endl;
    
}