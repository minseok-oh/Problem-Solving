#include <bits/stdc++.h>
using namespace std;
int t;

void solve() {
    cin >> t;
    while (t--) {
        string test;
        cin >> test;

        int ret = 0;
        stack<char> s;
        for (int i = 0; test[i]; i++) {
            if (test[i] == 'O') {
                s.push('O');
                ret += s.size();
            } else {
                while (!s.empty()) s.pop();
            }
        }
        cout << ret << "\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}