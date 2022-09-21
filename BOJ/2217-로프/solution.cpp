#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> rope;

void input() {
    cin >> n;
    rope.resize(n);

    for(int i = 0; i < n; i++) cin >> rope[i];
}

void solve() {
    sort(rope.begin(), rope.end());
    
    int res = -1;
    for(int i = 0; i < n; i++) res = max(res, rope[i] * (n - i));
    cout << res << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}