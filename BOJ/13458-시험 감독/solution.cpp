#include <bits/stdc++.h>
using namespace std;
long long n, b, c;
vector<long long> A;

void input() {
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cin >> b >> c;
}

void solve() {
    long long ans = n;
    for (int i = 0; i < n; i++) A[i] -= b;

    for (int i = 0; i < n; i++) {
        if (A[i] < 0) continue;
        if (A[i] % c == 0) {
            ans += (A[i] / c);
        } else {
            ans += (A[i] / c + 1);
        }
    }
    cout << ans << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}