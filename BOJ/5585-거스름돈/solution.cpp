#include <bits/stdc++.h>
using namespace std;
int money;
const int coin[6] = { 500, 100, 50, 10, 5, 1 };

void solve() {
    cin >> money;
    money = 1000 - money;

    int res = 0;
    for(int i = 0; i < 6; i++) {
        res += (money / coin[i]);
        money %= coin[i];
    }
    cout << res << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}