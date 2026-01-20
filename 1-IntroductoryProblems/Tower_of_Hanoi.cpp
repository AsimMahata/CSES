#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
vector<pair<int,int>> moves;
 
void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;
    hanoi(n-1, from, aux, to);       // move n-1 disks from source to aux
    moves.push_back({from, to});     // move largest disk
    hanoi(n-1, aux, to, from);       // move n-1 disks from aux to destination
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    hanoi(n, 1, 3, 2);
 
    cout << moves.size() << "\n";
    for (auto [a, b] : moves) {
        cout << a << " " << b << "\n";
    }
 
    return 0;
}