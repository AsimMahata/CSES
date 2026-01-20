#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;
 
//                               << SOLVE HERE >>
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    sort(s.begin(),s.end());
    vector<string> ans;
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans.size()<<endl;
    for(auto &x:ans)cout<<x<<endl;
}