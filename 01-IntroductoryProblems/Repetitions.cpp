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
 
    string s;cin>>s;
    ll ans=0;
    ll ct=1;
    for(int i=0;i<sz(s)-1;i++){
        if(s[i]==s[i+1])ct++;
        else {
            ans=max(ans,ct);
            ct=1;
        }
    }
            ans=max(ans,ct);
            cout<<ans<<endl;
    
 
}