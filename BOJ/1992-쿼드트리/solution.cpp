#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> video;

void input() {
    cin >> n;
    video.resize(n);

    for(int i = 0; i < n; i++) cin >> video[i];
}

void solve(int y, int x, int size) {
    bool ok = true;
    char first = video[y][x];
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if (first != video[i][j]) ok = false;
        }
    }

    if (ok) {
        cout << first;        
    }
    else {
        cout << "(";
        size /= 2;
        solve(y, x, size);
        solve(y, x + size, size);
        solve(y + size, x, size);
        solve(y + size, x + size, size);
        cout << ")";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve(0, 0, n);
    return 0;
}