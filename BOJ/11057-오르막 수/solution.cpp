#include <bits/stdc++.h>
using namespace std;
int n;
const int mod = 10007;

void solve() {
    int memo[1001][10] = { 0, };
    for (int i = 0; i <= 9; i++) memo[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        memo[i][0] = 1;
        for (int j = 1; j <= 9; j++) {
            for (int  k = 0; k <= j; k++) {
                memo[i][j] += memo[i - 1][k];
                memo[i][j] %= mod;
            }
        }
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
    cin >> n;
    solve();    
    return 0;
}