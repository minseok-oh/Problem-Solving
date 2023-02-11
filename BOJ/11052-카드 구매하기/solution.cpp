#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> P;

void input() {
    cin >> n;
    P.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> P[i];
}

void solve() {
    int memo[1001] = { 0, };
    memo[1] = P[1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            memo[i] = max(memo[i], P[j] + memo[i - j]);
        }
    }
    cout << memo[n] << "\n";
}

int main (void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}