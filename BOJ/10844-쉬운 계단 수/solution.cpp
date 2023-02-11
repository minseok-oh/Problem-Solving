#include <bits/stdc++.h>
using namespace std;
int n;
const int mod = 1000000000;

void solve() {
    cin >> n;

    int memo[101][10] = { 0, };
    for (int i = 1; i <= 9; i++) memo[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        memo[i][0] = memo[i - 1][1] % mod;
        for (int j = 1; j < 9; j++) {
            memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j + 1]) % mod;
        }
        memo[i][9] = memo[i - 1][8] % mod;
    }

    int ret = 0;
    for (int i = 0; i <= 9; i++) {
        ret += memo[n][i];
        ret %= mod;
    }    
    cout << ret << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}