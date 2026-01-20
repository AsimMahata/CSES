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
/*-----------------------------------------------------------------------------------------------------------------------------*/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

/*-----------------------------------------------------------------------------------------------------------------------------*/
//                               << SOLVE HERE >>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vll v(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i + 1];
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i <= m; i++)
        dp[0][i] = 1;
    if (v[1])
    {
        dp[1][v[1]] = 1;
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            dp[1][i] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (v[i])
        {
            if (v[i] - 1 >= 0)
                dp[i][v[i]] += dp[i - 1][v[i] - 1];
            dp[i][v[i]] += dp[i - 1][v[i]];
            if (v[i] + 1 <= m)
                dp[i][v[i]] += dp[i - 1][v[i] + 1];
            dp[i][v[i]] %= mod;
            continue;
        }
        for (int j = 1; j <= m; j++)
        {
            if (j == m)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] += dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] += dp[i - 1][j];
                dp[i][j] += dp[i - 1][j - 1];
            }
            dp[i][j] %= mod;
        }
    }
    ll ans = 0;

    for (int i = 0; i <= m; i++)
    {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
}