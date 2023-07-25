#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> arr;

void input() {
    cin >> n >> m;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void solve() {
    vector<int> sum(n, 0);
    sum[1] = arr[1];
    for (int i = 2; i <= n; i++) sum[i] = arr[i] + sum[i - 1];

    int i, j;
    for (int round = 0; round < m; round++) {
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << "\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}