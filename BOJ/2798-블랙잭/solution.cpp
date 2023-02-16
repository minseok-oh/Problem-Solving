#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> cards;

void input() {
    cin >> n >> m;
    cards.resize(n);
    for (int i = 0; i < n; i++) cin >> cards[i];
}

void solve() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int temp_ret = cards[i] + cards[j] + cards[k];
                if (temp_ret <= m) ret = max(ret, temp_ret);
            }
        }
    }
    cout << ret << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}