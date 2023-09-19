#include <bits/stdc++.h>
using namespace std;
long long n;
char board[9][9];

void input() {
    cin >> n;
}

void solve() {
    n %= 7;
    if (n == 0 || n == 2) cout << "CY\n";
    else cout << "SK\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}