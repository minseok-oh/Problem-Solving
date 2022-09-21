#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> A, B;

void input() {
    cin >> n;
    A.resize(n), B.resize(n);

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
}

void solve() {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int res = 0;
    for(int i = 0; i < n; i++) {
        res += (A[i] * B[n - i - 1]);
    }
    cout << res << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}