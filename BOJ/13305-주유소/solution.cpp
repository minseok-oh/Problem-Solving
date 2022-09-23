#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> dist, liter;

void input() {
    cin >> n;
    dist.resize(n - 1);
    liter.resize(n);

    for(int i = 0; i < n - 1; i++) cin >> dist[i];
    for(int i = 0; i < n; i++) cin >> liter[i];
}

void setLiterCost() {
    long long min_liter = liter[0];
    for (int i = 1; i < n; i++) {
        min_liter = min(min_liter, liter[i]);
        liter[i] = min(liter[i], min_liter);
    }
}

void solve() {
    setLiterCost();

    long long res = 0;
    for(int i = 0; i < n - 1; i++) {
        res += (dist[i] * liter[i]);
    }
    cout << res << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}