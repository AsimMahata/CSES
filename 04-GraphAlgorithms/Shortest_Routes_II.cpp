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
    ll n,m,q;cin>>n>>m>>q;
    vector<vll> a(n,vll(n,1e15));
    for(int i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        --u,--v;
        a[u][v]=min(a[u][v],w);
        a[v][u]=min(a[v][u],w);
    }
    for(int i=0;i<n;i++)a[i][i]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    while(q--){
        ll u,v;cin>>u>>v;
        --u,--v;
        if(a[u][v]==1e15)a[u][v]=-1;
        cout<<a[u][v]<<endl;
    }
}