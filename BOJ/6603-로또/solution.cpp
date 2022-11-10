#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> S, ans;

void input() {
    cin >> k;

    S.resize(k);
    for(int i = 0; i < k; i++) {
        cin >> S[i];
    }
}

void dfs(int here, int count) {
    if (count == 0) {
        for(int iter: ans) cout << S[iter] << " ";
        cout << "\n";
        return;
    }

    for(int i = here + 1; i < S.size(); i++) {
        ans.push_back(i);
        dfs(i, count-1);
        ans.pop_back();
    }
}

void solve() {
    while(1) {
        input();
        if(k == 0) break;

        dfs(-1, 6);
        cout << "\n";
        S.clear();
    }
}

int main(void) { 
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}