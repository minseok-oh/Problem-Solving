#include <bits/stdc++.h>
using namespace std;
int in[5];

void input() {
    for (int i = 0; i < 5; i++) {
        cin >> in[i];
    }
}

void solve() {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += (in[i] * in[i]);
    }
    cout << sum % 10 << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}