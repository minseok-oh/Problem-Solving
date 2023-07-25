#include <bits/stdc++.h>
using namespace std;
int a, b;

int D(int here) {
    return (2 * here) % 10000;
}

int S(int here) {
    return here > 0? here - 1: 9999;
}

int L(int here) {
    return ((here % 1000) * 10) + (here / 1000);
}

int R(int here) {
    return ((here % 10) * 1000) + (here / 10);
}

string solve() {
    queue<pair<int, string>> q;
    bool visited[10001] = { false, };

    q.push(make_pair(a, ""));
    visited[a] = true;

    while (!q.empty()) {
        int here = q.front().first;
        string op = q.front().second; q.pop();
        if (here == b) return op;

        int next;
        next = D(here);
        if (!visited[next]) {
            visited[next] = true;
            q.push(make_pair(next, op + 'D'));
        }

        next = S(here);
        if (!visited[next]) {
            visited[next] = true;
            q.push(make_pair(next, op + 'S'));
        }

        next = L(here);
        if (!visited[next]) {
            visited[next] = true;
            q.push(make_pair(next, op + 'L'));
        }

        next = R(here);
        if (!visited[next]) {
            visited[next] = true;
            q.push(make_pair(next, op + 'R'));
        }
    }
    return "";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << solve() << "\n";
    }
    return 0;
}