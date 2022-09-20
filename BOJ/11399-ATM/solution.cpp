#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> P;

void input() {
    cin >> n;
    P.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> P[i];
    }
}

void solve() {
    sort(P.begin(), P.end());

    int res = 0, acc = 0;
    for(int i = 0; i < n; i++) {
        acc += P[i];
        res += acc;
    }
    cout << res << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}