#include <bits/stdc++.h>
using namespace std;
string in = "";

void input() {
    char num;
    for (int i = 0; i < 8; i++) {
        cin >> num;
        in += num;
    }
}

void solve() {
    if (in == "12345678") {
        cout << "ascending\n";
    } else if (in == "87654321") {
        cout << "descending\n";
    } else {
        cout << "mixed\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}