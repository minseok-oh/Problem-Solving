#include <bits/stdc++.h>
using namespace std;
int n, k;

void input() {
    cin >> n >> k;
}

int solve(int n, int k) {
    if (n == 1) return 1;
    if (n == k || k == 0) return 1;

    int left = solve(n - 1, k - 1);
    int right = solve(n - 1, k);
    return left + right;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    cout << solve(n, k) <<  "\n";
    return 0;
}