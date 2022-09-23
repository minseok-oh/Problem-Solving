#include <bits/stdc++.h>
using namespace std;
long long s;

void solve() {
    cin >> s;

    long long res = 0, here = 0;
    while (res <= s) {
        here++;
        res += here;
    }

    if(res > s) here--;
    cout << here << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}