#include <bits/stdc++.h>
using namespace std;
int fibo[41][2] = { 0, };

void init(){
    fibo[0][0] = 1; fibo[1][1] = 1;
    for(int i = 2; i <= 40; i++){
        fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
        fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
    }
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << fibo[n][0] << " " << fibo[n][1] << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    solve();
    return 0;
}