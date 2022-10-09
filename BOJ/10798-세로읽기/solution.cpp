#include <bits/stdc++.h>
using namespace std;
int max_len = -1;
vector<string> strs;

void input() {
    strs.resize(5);
    for(int i = 0; i < 5; i++) {
        cin >> strs[i];
        max_len = max(max_len, (int)strs[i].size());
    }
}

void solve() {
    for(int i = 0; i < max_len; i++) {
        for(int j = 0; j < 5; j++) {
            if((int)strs[j].size() < i) continue;
            if('A' <= strs[j][i] && strs[j][i] <= 'Z' ||
                'a' <= strs[j][i] && strs[j][i] <= 'z' ||
                '0' <= strs[j][i] && strs[j][i] <= '9')
            cout << strs[j][i];
        }
    }
    cout << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}