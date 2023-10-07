#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> books, beforeZero, afterZero;

void input() {
    cin >> n >> m;
    books.resize(n);
    for (int i = 0; i < n; i++) cin >> books[i];
}

void init() {
    for (int i: books) {
        if (i > 0) afterZero.push_back(i);
        else beforeZero.push_back(-1 * i);
    }
    sort(beforeZero.begin(), beforeZero.end(), greater<int>());
    sort(afterZero.begin(), afterZero.end(), greater<int>());
}

void solve() {
    vector<int> dist;
    for (int i = 0; i < beforeZero.size(); i += m) {
        dist.push_back(beforeZero[i]);
    }

    for (int i = 0; i < afterZero.size(); i += m) {
        dist.push_back(afterZero[i]);
    }
    sort(dist.begin(), dist.end());

    int res = 0;
    for (int i = 0; i < dist.size() - 1; i++) res += (dist[i] * 2);
    res += dist[dist.size() - 1];
    cout << res << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    init();
    solve();
    return 0;
}