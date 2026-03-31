#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> edges;
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({u, v, w});
    }

    vector<ll> dis(n, 0), parent(n, -1);

    ll x = -1;

    // Bellman-Ford
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto &e : edges) {
            ll u = e[0], v = e[1], w = e[2];
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    // move inside cycle
    for (int i = 0; i < n; i++) x = parent[x];

    vector<ll> cycle;
    ll cur = x;

    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != x);

    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (auto &v : cycle) cout << v + 1 << " ";
    cout << "\n";

    return 0;
}