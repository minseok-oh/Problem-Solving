#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> stair, dp;

void input(){
    cin >> n;
    stair.resize(n + 1);
    dp.resize(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> stair[i];
    }
}

void make_dp(){
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
    for(int i = 4; i <= n; i++){
        dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]) + stair[i];
    }
    cout << dp[n] << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    make_dp();
    return 0;
}