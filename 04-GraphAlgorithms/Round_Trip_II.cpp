#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> g;
vector<ll> vis, par;
ll st = -1, ed = -1;

bool dfs(ll u) {
    vis[u] = 1; 

    for (auto v : g[u]) {
        if (vis[v] == 0) {
            par[v] = u;
            if (dfs(v)) return true;
        }
        else if (vis[v] == 1) {
            st = u;
            ed = v;
            return true;
        }
    }

    vis[u] = 2; 
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    g.assign(n, {});
    vis.assign(n, 0);
    par.assign(n, -1);

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i)) break;
        }
    }

    if (st == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<ll> cycle;
        cycle.push_back(ed);

        for (ll v = st; v != ed; v = par[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(ed);

        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (auto x : cycle) cout << x + 1 << " ";
    }
}