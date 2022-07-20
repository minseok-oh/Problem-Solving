#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> lion[3];
const int mod = 9901;

void init(int finish){
    lion[0][1] = lion[1][1] = lion[2][1] = 1;
    for(int i = 2; i <= n; i++){
        lion[0][i] = (lion[0][i - 1] + lion[1][i - 1] + lion[2][i - 1]) % mod;
        lion[1][i] = (lion[0][i - 1] + lion[2][i - 1]) % mod;
        lion[2][i] = (lion[0][i - 1] + lion[1][i - 1]) % mod;
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < 3; i++) lion[i].resize(n + 1);

    init(n);
    cout << (lion[0][n] + lion[1][n] + lion[2][n]) % mod<< "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}