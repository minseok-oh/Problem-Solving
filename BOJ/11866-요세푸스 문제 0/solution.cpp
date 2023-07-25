#include <bits/stdc++.h>
using namespace std;
int n, k;

void input() {
    cin >> n >> k;
}

void solve() {
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    cout << "<";
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < k - 1; j++) {
            int here = q.front(); q.pop();
            q.push(here);
        }

        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}