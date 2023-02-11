#include <bits/stdc++.h>
using namespace std;

int memo[21][21][21] = { 0, };
int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    int& ret = memo[a][b][c];
    if (ret != 0) return ret;

    if (a < b && b < c) {
        ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    } else {
        ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    return ret;
}

void solve() {
    int a, b, c;
    while(1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) return ;

        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        cout << w(a, b, c) << "\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}