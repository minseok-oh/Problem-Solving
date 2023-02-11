#include <bits/stdc++.h>
using namespace std;
int n, k;
const int mod = 1000000000;

void input() {
    cin >> n >> k;
}

int memo[201][201] = { 0, };
int dp(int here, int num) {
    if (num == 0) {
        if (here == 0) return 1;
        else return 0;
    }

    int& ret = memo[here][num];
    if(ret != 0) return ret;

    for (int i = 0; i <= here; i++) {
        ret += dp(here - i, num - 1);
        ret %= mod;        
    }
    return ret;
}

void solve() {
    cout << dp(n, k) % mod << "\n";
}

int main (void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}