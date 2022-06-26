#include <bits/stdc++.h>
using namespace std;
int n, k, max_value = -1;
vector<int> pots;

void input(){
    cin >> n >> k;
    pots.resize(n);
    for(int i = 0; i < n; i++){
        cin >> pots[i];
        max_value = max(max_value, pots[i]);
    }
}

long long count_split(long long cap){
    long long res = 0;
    for(int i = 0; i < n; i++) res += (pots[i] / cap);
    return res;
}

void solve(){
    long long left = 1, right = max_value;
    while(left <= right){
        long long mid = (left + right) / 2;

        long long here = count_split(mid);
        if(here < k){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << right << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}