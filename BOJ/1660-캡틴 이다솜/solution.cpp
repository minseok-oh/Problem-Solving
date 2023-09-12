#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> triangle_size;
bool triangle[300001] = { false, };

void input() {
    cin >> n;
}

void init() {
    int temp = 0;
    for (int i = 1; temp <= n; i++) {
        temp += (i * (i + 1) / 2);

        triangle[temp] = true;
        triangle_size.push_back(temp);
    }
}

void solve() {
    int memo[300001] = { 0, };
    for (int i = 1; i <= n; i++) {
        if (triangle[i]) memo[i] = 1;
        else {
            memo[i] = 300000;
            for (int j = 0; triangle_size[j] <= i; j++) {
                memo[i] = min(memo[i], memo[i - triangle_size[j]] + 1);
            }
        }
    }
    cout << memo[n] << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    init();
    solve();
    return 0;
}