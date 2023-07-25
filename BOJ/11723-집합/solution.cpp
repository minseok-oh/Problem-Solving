#include <bits/stdc++.h>
using namespace std;
int m, s = 0;
const string emptyNumber[2] = { "all", "empty" };

void add(int n) {
    s |= (1 << n);
}

void remove(int n) {
    s &= ~(1 << n);
}

void check(int n) {
    if (s & (1 << n)) cout << "1\n";
    else cout << "0\n";
}

void toggle(int n) {
    s ^= (1 << n);
}

void all() {
    s = (1 << 20) - 1;
}

void empty() {
    s = 0;
}

void solve() {
    int num;
    string op;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op != emptyNumber[0] && op != emptyNumber[1]) {
            cin >> num;
        }

        if (op == "add") add(num - 1);
        else if (op == "remove") remove(num - 1);
        else if (op == "check") check(num - 1);
        else if (op == "toggle") toggle(num - 1);
        else if (op == "all") all();
        else if (op == "empty") empty();
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> m;
    solve();
    return 0;
}