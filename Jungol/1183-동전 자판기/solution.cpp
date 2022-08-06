#include <bits/stdc++.h>
using namespace std;
int w;
int money_count[6] = { 0, };

void input(){
    cin >> w;
    for(int i = 0; i < 6; i++){
        cin >> money_count[i];
    }
}

const int money_value[6] = { 500, 100, 50, 10, 5, 1 };
void solve(){
    int ans[6] = { 0, };
    ans[5] = w;
    for(int j = 5; j > 0; j--){
        while(ans[j] > money_count[j]){
            ans[j] -= (money_value[j - 1] / money_value[j]);
            ans[j - 1]++;
        }
    }
    
    int sum = 0;
    for(int i = 0; i < 6; i++) sum += ans[i];

    cout << sum << "\n";
    for(int i = 0; i < 6; i++){
        cout << ans[i] << " ";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}