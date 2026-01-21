#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
 
#define ll long long
int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  set<ll> points;
  for (auto &e : a) {
    cin >> e.first >> e.second;
    points.insert(e.first);
    points.insert(e.second);
  }
  unordered_map<ll, ll> mp;
  mp.reserve(n);
  int cord = 0;
  for (auto &x : points)
    mp[x] = cord++;
  vector<ll> R(points.size() + 10);
  for (auto &e : a) {
    ll l = mp[e.first];
    ll r = mp[e.second];
    R[l]++;
    R[r + 1]--;
  }
  for (int i = 1; i < (int)R.size(); i++)
    R[i] += R[i - 1];
  cout << *max_element(R.begin(), R.end()) << endl;
}