#include <bits/stdc++.h>
using namespace std;
string a, b;

void input() {
    cin >> a >> b;
}

void solve() {
    int res = -1;
    int memo[1001][1001] = { 0, };
    for (int col = 1; col <= a.size(); col++) {
        for (int row = 1; row <= b.size(); row++) {
            int i = col-1, j=row-1;
            if (a[i] == b[j]) {
                memo[col][row] = memo[col-1][row-1] + 1;
            } else {
                memo[col][row] = max(memo[col-1][row], memo[col][row-1]);
            }
            res = max(res, memo[col][row]);
        }    
    }
    cout << res << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}