#include <bits/stdc++.h>
using namespace std;
int day;
int cars[5];

void input() {
    cin >> day;
    for(int i = 0; i < 5; i++) cin >> cars[i];
}

void solve() {
    int res = 0;
    for(int i = 0; i < 5; i++) {
        if(day == cars[i]) res++;
    }
    cout << res << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}