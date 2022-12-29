#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> t, p;

void input() {
    cin >> n;
    t.resize(n + 1);
    p.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
}

int brute_force(int index) {
    int ret = 0, here_end = index + t[index] - 1;
    if (here_end > n) return 0;
    
    for (int i = index; i <= n; i++) {
        if (here_end < i) {
            ret = max(ret, brute_force(i));
        }
    }
    return p[index] + ret;
}

void solve() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, brute_force(i));
    }
    cout << res << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}