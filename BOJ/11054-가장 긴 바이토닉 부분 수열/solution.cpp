#include <bits/stdc++.h>
using namespace std;
int n, A[1001] = { 0, };

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
}

void solve() {
    int plus_memo[1001] = { 0, };
    plus_memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        plus_memo[i] = 1;
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) 
                plus_memo[i] = max(plus_memo[i], plus_memo[j] + 1);
        }
    }

    int minus_memo[1001] = { 0, };
    minus_memo[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        minus_memo[i] = 1;
        for (int j = n; j > i; j--) {
            if (A[j] < A[i]) 
                minus_memo[i] = max(minus_memo[i], minus_memo[j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, plus_memo[i] + minus_memo[i] - 1);
    }
    cout << res << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}