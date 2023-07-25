#include <bits/stdc++.h>
using namespace std;
int n, m;
string P;

void input() {
    cin >> n >> m >> P;
}

void solve() {
    vector<int> checksum(m, 0);
    for (int i = 0; i < m; i++) {
        if (P[i] == 'I') checksum[i] = 1;
    }

    for (int i = 1; i < m - 1; i++) {
        if (P[i] == 'O' && P[i + 1] == 'I') {
            checksum[i + 1] = checksum[i - 1] + 1;
        }
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        if (n < checksum[i]) res++;
    }
    cout << res << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}