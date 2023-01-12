#include <bits/stdc++.h>
using namespace std;
int a, b, c;

void solve() {
    while(1) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        bool isRec = false;
        if (a > b && a > c) {
            if (a * a == b * b + c * c) isRec = true;
        } else if (b > a && b > c) {
            if (b * b == a * a + c * c) isRec = true;
        } else {
            if (c * c == b * b + a * a) isRec = true;
        }

        if (isRec) cout << "right\n";
        else cout << "wrong\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}