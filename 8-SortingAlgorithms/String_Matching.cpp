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
 
    string s,t;cin>>s>>t;
     s=t+"X"+s;
    ll n=sz(s);
    ll len=0;
    ll i=1;
    vector<ll> pref(n+1,0);
    while(i<n){
        if(s[i]==s[len]){
            len++;
            pref[i]=len;
            i++;
        }else{
            if(len){
                len=pref[len-1];
                
            }else{
                pref[i++]=0;
            }
        }
    }
    ll ct=0;
    for(auto &c : pref)if(c==sz(t))ct++;
    cout<<ct<<endl;
}