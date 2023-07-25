#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int pr[101];
bool visited[101];

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> pr[i];
        visited[i] = false;
    }
}

void solve() {
    queue<int> q;
    for (int i = 0; i < n; i++) q.push(i);

    int res = 1;
    while (!q.empty()) {
        int here = q.front(); q.pop();

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && pr[i] > pr[here]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            if (here == m) {
                cout << res << "\n";
                break;
            }

            visited[here] = true;
            res++;
        }
        else {
            q.push(here);
        }
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}