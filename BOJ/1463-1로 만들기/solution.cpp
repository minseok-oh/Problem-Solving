#include <bits/stdc++.h>
using namespace std;
const int MAX = 987654321;

int dp[1000001] = { 0, };
int operation(int here) {
    int& ret = dp[here];
    if (ret != MAX) return ret;

    if (here % 3 == 0) ret = min(ret, operation(here / 3) + 1);
    if (here % 2 == 0) ret = min(ret, operation(here / 2) + 1);
    ret = min(ret, operation(here - 1) + 1);
    return ret;
}

void init() {
    for (int i = 0; i < 1000001; i++) dp[i] = MAX;
    dp[1] = 0;
}

void solve() {
    int x;
    cin >> x;
    cout << operation(x) << "\n";;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    solve();
    return 0;
}