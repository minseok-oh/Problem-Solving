#include <bits/stdc++.h>
using namespace std;
int n;
vector<short> board[3];
int max_dp[3][2], min_dp[3][2];

void input(){
    cin >> n;
    for(int i = 0; i < 3; i++){
        board[i].resize(n + 1);
    }

    for(int i = 1; i <= n; i++){
        cin >> board[0][i] >> board[1][i] >> board[2][i];
    }
}

void init(){
    max_dp[0][0] = min_dp[0][0] = board[0][1];
    max_dp[1][0] = min_dp[1][0] = board[1][1];
    max_dp[2][0] = min_dp[2][0] = board[2][1];

    for(int i = 2; i <= n; i++){
        max_dp[0][1] = max(max_dp[0][0], max_dp[1][0]);
        min_dp[0][1] = min(min_dp[0][0], min_dp[1][0]);

        max_dp[2][1] = max(max_dp[2][0], max_dp[1][0]);
        min_dp[2][1] = min(min_dp[2][0], min_dp[1][0]);

        max_dp[1][1] = max(max_dp[0][1], max_dp[2][1]);
        min_dp[1][1] = min(min_dp[0][1], min_dp[2][1]);

        for(int j = 0; j < 3; j++){
            max_dp[j][0] = max_dp[j][1] + board[j][i];
            min_dp[j][0] = min_dp[j][1] + board[j][i];
        }
    }
}

void solve(){
   cout << max(max_dp[0][0], max(max_dp[1][0], max_dp[2][0])) << " ";
   cout << min(min_dp[0][0], min(min_dp[1][0], min_dp[2][0])) << "\n"; 
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    init();
    solve();
    return 0;
}