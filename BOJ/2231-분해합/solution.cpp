#include <bits/stdc++.h>
using namespace std;
int n;

int constructor(int m) {
    int ret = m;
    while (m > 0) {
        ret += m % 10;
        m /= 10;
    }
    return ret;
}

void solve() {
    for (int i = 1; i < n; i++) {
        int ret = constructor(i);
        if (n == ret) {
            cout << i << "\n";
            return;
        }
    }
    cout << "0\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    solve();
    return 0;
}