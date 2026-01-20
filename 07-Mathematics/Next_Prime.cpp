#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
 
using u64 = uint64_t;
using u128 = __uint128_t;
 
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}
 
bool MillerRabin(u64 n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
 
    // write n-1 as d * 2^s
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
 
  
    static const u64 bases[] = {2,3,5,7,11,13,17,19,23,29,31,37};
 
    for (u64 a : bases) {
        if (a >= n) break;
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        ll n; cin >> n;
        for (ll x = n + 1; x <= n + 100000; x++) {
            if (MillerRabin(x)) {
                cout << x << endl;
                break;
            }
        }
    }
}