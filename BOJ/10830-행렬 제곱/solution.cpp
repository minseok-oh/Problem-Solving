#include <bits/stdc++.h>
using namespace std;
int n; long long B;
vector<vector<int>> A;
const int mod = 1000;

void input() {
    cin >> n >> B;
    vector<int> temp(n, 0);
    for (int i = 0; i < n; i++) A.push_back(temp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            A[i][j] %= mod;
        }
    }
}

vector<vector<int>> multiply(vector<vector<int>> m1, vector<vector<int>> m2) {
    vector<vector<int>> ret;
    vector<int> temp(n, 0);
    for (int i = 0; i < n; i++) ret.push_back(temp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret[i][j] += ((m1[i][k] % mod) * (m2[k][j] % mod) % mod);
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

vector<vector<int>> square(long long m) {
    if (m == 1) return A;
    
    if (m % 2 == 0) {
        vector<vector<int>> temp = square(m / 2);
        return multiply(temp, temp);
    }
    return multiply(A, square(m - 1));
}

void solve() {
    vector<vector<int>> ret = square(B);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}