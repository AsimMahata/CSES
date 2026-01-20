#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
 

int togray(int x) {
    return x ^ (x >> 1);
}
 

string tostringbin(int x, int n) {
    string s;
    for (int i = n - 1; i >= 0; i--) {
        s.push_back(((x >> i) & 1) + '0');
    }
    return s;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int gray = togray(i);
        string res = tostringbin(gray, n);
        cout << res <<endl;
    }
   
}