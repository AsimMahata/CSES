#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
const int mod = 1e9 + 7;
// const int mod = 998244353;
struct SegTree
{
    int n;
    vector<long long> t;
 
    SegTree(const vector<long long> &a)
    {
        n = a.size();
        t.resize(4 * n);
        build(a, 1, 0, n);
    }
 
    inline long long build(const vector<long long> &a, int v, int l, int r)
    {
        if (l + 1 == r)
            return t[v] = a[l];
        int m = (l + r) >> 1;
        return t[v] = min(build(a, v << 1, l, m),
                          build(a, v << 1 | 1, m, r));
    }
 
    inline long long update(int v, int l, int r, int pos, long long val)
    {
        if (l + 1 == r)
            return t[v] = val;
        int m = (l + r) >> 1;
        if (pos < m)
            update(v << 1, l, m, pos, val);
        else
            update(v << 1 | 1, m, r, pos, val);
        return t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
 
    inline long long query(int v, int l, int r, int L, int R)
    {
        if (L >= r || R <= l)
            return LLONG_MAX; // no overlap
        if (L <= l && r <= R)
            return t[v]; // full overlap
        int m = (l + r) >> 1;
        return min(query(v << 1, l, m, L, R),
                   query(v << 1 | 1, m, r, L, R));
    }
};
 
//                               << SOLVE HERE >>
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> mm(n), pp(n);
    for (int i = 0; i < n; i++)
    {
        mm[i] = a[i] - i;
        pp[i] = a[i] + i;
    }
    SegTree mns(mm), pls(pp);
 
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll k, x;
            cin >> k >> x;
            --k;
            mns.update(1, 0, n, k, x - k);
            pls.update(1, 0, n, k, x + k);
            a[k] = x;
        }
        else
        {
            ll k;
            cin >> k;
            --k;
            ll left = (k > 0 ? mns.query(1, 0, n, 0, k) + k : LLONG_MAX);
            ll right = (k + 1 < n ? pls.query(1, 0, n, k + 1, n) - k : LLONG_MAX);
            ll curr = a[k];
            
            cout << min({left, curr, right}) << endl;
        }
    }
}