#include <bits/stdc++.h>
using namespace std;
int n, m;
bool isok[10];

void input() {
    cin >> n >> m;
    for (int i = 0; i < 10; i++) isok[i] = true;
    
    int ok;
    for (int i = 0; i < m; i++) {
        cin >> ok;
        isok[ok] = false;
    }
}

bool isRemote(int num) {
    if (num == 0) return isok[num];
    
    while (num != 0) {
        if (!isok[num % 10]) {
            return false;
        }
        num /= 10;
    }
    return true;
}

void solve() {
    int res = abs(100 - n);
    for (int i = 0; i < 1000000; i++) {
        if (isRemote(i)) {
            string temp = to_string(i);
            res = min(res, (int)(temp.size() + abs(i - n)));
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