#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;
 
//                               << SOLVE HERE >>
const ll inf = 1e18;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    vector<ll> a(n+2,inf);
    vector<pair<ll,ll>> p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p.push_back({a[i],i});
    }
    sort(p.begin(),p.end());
    stack<ll> st;
    st.push(0);
    vector<ll> left(n+2,0),right(n+2,n+1);
    for(int i=1;i<=n;i++){
        while(a[st.top()]<=a[i])st.pop();
        left[i]=st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();
    st.push(n+1);
    for(int i=n;i>=1;i--){
        while(a[st.top()]<=a[i])st.pop();
        right[i]=st.top();
        st.push(i);
    }
    vector<ll> dp(n+2,0);
    for(auto &[x,m]:p){
        ll l = left[m];
        ll r= right[m];
        dp[l]=max(dp[l],dp[m]+1);
        dp[r]=max(dp[r],dp[m]+1);
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
}