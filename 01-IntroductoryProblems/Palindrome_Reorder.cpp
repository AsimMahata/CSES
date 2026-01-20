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
    map<char,ll> f;
    for(auto &c:s)f[c]++;
    char mid=' ';
    bool pos=true;
    bool oddcnt=0;
    string half;
    for(auto &[c,cnt]:f){
        if(cnt&1){
            if(oddcnt){
                pos=false;
                break;
            }
            oddcnt=1;
            mid=c;
        }
        for(int i=0;i<cnt/2;i++)half.push_back(c);
    }
    if(!pos){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    string ans=half;
    if(oddcnt)ans.push_back(mid);
    reverse(half.begin(),half.end());
    ans+=half;
    cout<<ans<<endl;
}