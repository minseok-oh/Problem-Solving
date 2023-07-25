#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> diff;

void input() {
    cin >> n;
    diff.resize(n);
    for (int i = 0; i < n; i++) cin >> diff[i];
}

void solve() {
    if (n == 0) {
        cout << "0\n";
        return ;
    }
    
    sort(diff.begin(), diff.end());
    int limit = round(n * 0.15);

    int sum = 0;
    for (int i = limit; i < n - limit; i++) {
        sum += diff[i];
    }

    cout << round((double)sum / (n - 2 * limit)) << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}