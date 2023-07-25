#include <bits/stdc++.h>
using namespace std;
int m, n, x, y;

void input() {
    cin >> m >> n >> x >> y;
}

int makeGcd(int a, int b) {
    if (b == 0) return a;
    else return makeGcd(b, a % b);
}

void solve() {
    int len = m * n / makeGcd(max(m, n), min(m, n));

    for (int i = 0; i <= len; i += m) {
        int here = i + x;
        if ((here - y) % n == 0) {
            cout << i + x << "\n";
            return;
        }
    }
    cout << "-1\n";
}

void iteration() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    iteration();
    return 0;
}