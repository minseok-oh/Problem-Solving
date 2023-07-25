#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string name, cloth;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> name >> cloth;
        if (m.find(cloth) != m.end()) m[cloth]++;            
        else m[cloth] = 1;
    }

    int res = 1;
    for (auto a: m) {
        res *= (a.second + 1);
    }
    cout << res - 1 << "\n";
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}