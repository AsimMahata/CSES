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
 
/*------------------------------------------------------*/
// Binary Multiplication (Prevents Overflow)
ll binMul(ll a, ll b, ll M) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % M;
        a = (a * 2) % M;
        b >>= 1;
    }
    return res;
}
 
// Binary Exponentiation (Fast Power Calculation)
ll binExp(ll a, ll b, ll M) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res*a)%M;
        a = (a*a)%M;
        b >>= 1;
    }
    return res;
}
 
// Modular Inverse (Using Fermat’s Theorem)
ll inv(ll k) {
    return binExp(k, mod - 2, mod);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    ll p = 0, len = 1, sum = 1, product = 1, lm = 1;
    
    for (int i = 0; i < n; i++) {
        ll x, k;
        cin >> x >> k;
 
        p = binMul(k&1?k:k/2, (k + 1)&1?(k+1):((k+1)/2), mod - 1);  // Avoids overflow
        product = binMul(binExp(product,(k+1)%(mod-1),mod), binExp(x, binMul(lm, p, mod - 1), mod), mod);
        ll tot = (binExp(x, k + 1, mod) - 1 + mod) % mod;
        tot = binMul(tot, inv(x - 1), mod);
 
        sum = binMul(sum, tot, mod);
        lm = binMul(lm, k + 1, mod - 1);
        len = binMul(len, k + 1, mod);
    }
 
    cout << len << " " << sum << " " << product << endl;
}