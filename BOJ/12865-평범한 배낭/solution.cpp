#include <bits/stdc++.h>
using namespace std;
int n, k;
int memo[101][100001];
vector<int> weight, value;

void input() {
    cin >> n >> k;

    weight.resize(n + 1);
    value.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - weight[i] >= 0) memo[i][j] = max(memo[i-1][j], memo[i-1][j-weight[i]] + value[i]);
            else memo[i][j] = memo[i-1][j];
        }
    }
    cout << memo[n][k] << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}