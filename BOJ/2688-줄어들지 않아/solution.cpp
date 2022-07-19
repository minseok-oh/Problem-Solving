#include <bits/stdc++.h>
using namespace std;
long long dp[65][11] = { 0, };

void init(){
    for(int i = 0; i <= 9; i++) dp[1][i] = 1;

    for(int i = 2; i <= 64; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        long long ans = 0;
        for(int i = 0; i <= 9; i++) ans += dp[n][i];
        cout << ans << "\n"; 
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    solve();
    return 0;
}