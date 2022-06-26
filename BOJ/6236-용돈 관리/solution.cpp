#include <bits/stdc++.h>
using namespace std;
int n, m, max_value = -1, sum_value = 0;
vector<int> money;

void input(){
    cin >> n >> m;
    money.resize(n);
    for(int i = 0; i < n; i++){
        cin >> money[i];
        max_value = max(max_value, money[i]);
        sum_value += money[i];
    }
}

int count_withdraw(int cost){
    int ret = 1, sum = money[0];
    for(int i = 1; i < n; i++){
        if(sum + money[i] <= cost){
            sum += money[i];
        }
        else{
            sum = money[i];
            ret++;
        }
    }
    return ret;
}

void solve(){
    int left = max_value, right = sum_value;
    while(left <= right){
        int mid = (left + right) / 2;

        int here = count_withdraw(mid);
        if(here <= m){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << left << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}