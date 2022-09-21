#include <bits/stdc++.h>
using namespace std;
int t;
const int button[3] = { 300, 60, 10 };

void solve() {
    cin >> t;

    int res[3] = { 0, };
    for(int i = 0; i < 3; i++) {
        res[i] = (t / button[i]);
        t %= button[i];
    }

    if(t == 0) {
        cout << res[0] << " " << res[1] << " " << res[2] << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}