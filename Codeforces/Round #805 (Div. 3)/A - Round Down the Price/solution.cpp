#include <bits/stdc++.h>
using namespace std;
int t;
vector<long long> n, round_n;

void init(){
    round_n.resize(10);
    round_n[0] = 1;
    for(int i = 1; i <= 9; i++){
        round_n[i] = round_n[i - 1] * 10;
    }
}

void input(){
    cin >> t;
    n.resize(t);
    for(int i = 0; i < t; i++) cin >> n[i];
}

void solve(){
    for(int i = 0; i < t; i++){
        int here = n[i], value = 0;
        if(here == round_n[9]){
            cout << "0\n";
            continue;
        }
        
        for(int i = 0; i < 9; i++){
            if(round_n[i] <= here && here < round_n[i + 1]){
                value = i;
            }
        }
        cout << here - round_n[value] << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    input();
    solve();
    return 0;
}