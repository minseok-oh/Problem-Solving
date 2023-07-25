#include <bits/stdc++.h>
using namespace std;
int n, m;
map<string, string> mp;

void input() {
    cin >> n >> m;
    
    string url, password;
    for (int i = 0; i < n; i++) {
        cin >> url >> password;
        mp[url] = password;
    }
}

void solve() {
    string url;
    for (int i = 0; i < m; i++) {
        cin >> url;
        cout << mp[url] << "\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}