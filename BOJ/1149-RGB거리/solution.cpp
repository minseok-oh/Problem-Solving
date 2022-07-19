#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> house[3], dp[3];

void input(){
    cin >> n;
    for(int i = 0; i < 3; i++){
        house[i].resize(n + 1);
        dp[i].resize(n + 1);
    }

    for(int i = 1; i <= n; i++){
        cin >> house[0][i] >> house[1][i] >> house[2][i];
    }
}

void init(){
    dp[0][1] = house[0][1];
    dp[1][1] = house[1][1];
    dp[2][1] = house[2][1];
    for(int i = 2; i <= n; i++){
        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + house[0][i];
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + house[1][i];
        dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + house[2][i];
    }
}

void solve(){
    init();
    cout << min(dp[0][n], min(dp[1][n], dp[2][n])) << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}