#include <bits/stdc++.h>
using namespace std;
int n, memo[50001];

void init() {
    cin >> n;
    for (int i = 0; i <= n; i++) memo[i] = 4;

    memo[0] = 0;
    for (int i = 1; i * i <= n; i++) memo[i * i] = 1;
}

void solve() {
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            memo[i] = min(memo[i], memo[i - j * j] + 1);
        }
    }
    cout << memo[n] << "\n";
}

int main(void) {
    init();
    solve();
    return 0;
}