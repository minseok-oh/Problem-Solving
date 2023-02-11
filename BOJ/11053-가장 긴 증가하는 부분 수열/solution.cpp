#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> A;

void input() {
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
}

void solve() {
    int memo[1001] = { 0, };

    int ret = 1;
    memo[0] = 1;
    for (int i = 1; i < n; i++) {
        memo[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
        ret = max(ret, memo[i]);
    }
    cout << ret << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}