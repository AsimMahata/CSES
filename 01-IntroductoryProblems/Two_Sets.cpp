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
    if(n==3){
        YES;
        cout<<2<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<1<<endl;
        cout<<3<<endl;
    }else if(n==7){
        YES;
        cout<<4<<endl;
        cout<<"1 2 4 7"<<endl;
        cout<<3<<endl;
        cout<<"3 5 6"<<endl;
 
}else{
    if(n&1){
        if(n%4==3){
            YES;
            vector<ll> a,b;
            a.pb(1);
            a.pb(2);
            b.pb(3);
            for(int i=4;i<=n;i+=4){
                a.pb(i);
                a.pb(i+3);
                b.pb(i+1);
                b.pb(i+2);
            }
            cout<<sz(a)<<endl;
            for(auto i : a)cout<<i<<" ";
            cout<<endl;
            cout<<sz(b)<<endl;
            for(auto i : b)cout<<i<<" ";
            cout<<endl;
        }else{
            NO;
        }
    }else{
        if((n/2)%2==0){
            YES;
            vector<ll> a,b;
            for(int i=1;i<=n/2;i+=2){
                a.pb(i);
                a.pb(n-i+1);
                b.pb(i+1);
                b.pb(n-i);
            }
            cout<<sz(a)<<endl;
            for(auto i : a)cout<<i<<" ";
            cout<<endl;
            cout<<sz(b)<<endl;
            for(auto i : b)cout<<i<<" ";
            cout<<endl;
        }else{
            NO;
        }
    }
}
}