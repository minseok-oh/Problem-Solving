#include <bits/stdc++.h>
using namespace std;
int k; multiset<int> ms;

void solve() {
    cin >> k;

    char op; int opCode;
    for (int i = 0; i < k; i++) {
        cin >> op >> opCode;

        if (op == 'I') {
            ms.insert(opCode);
        } else if (op == 'D') {
            if (ms.size() == 0) continue;

            if (opCode == -1) {
                auto iter = ms.begin();
                ms.erase(iter);
            } else {
                auto iter = --ms.end();
                ms.erase(iter);
            }
        }
    }

    if (ms.size() == 0) cout << "EMPTY";
    else {
        auto iter = --ms.end();
        cout << *iter << " ";
        
        iter = ms.begin();
        cout << *iter;
    }
    cout << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
        ms.clear();
    }
    return 0;
}