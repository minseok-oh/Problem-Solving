#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> money;

void input() {
    cin >> n >> k;
    money.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }
}

void solve() {
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        res += (k / money[i]);
        k %= money[i];
    }
    cout << res << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}