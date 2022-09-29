#include <bits/stdc++.h>
using namespace std;
long long a, b;

void input() {
    cin >> a >> b;
}

int bfs() {
    queue<pair<long long, int>> q;
    q.push(make_pair(a, 1));

    while(!q.empty()) {
        pair<long long, int> here = q.front();
        q.pop();
        if(here.first == b) return here.second;

        if (here.first * 2 <= b) {
            q.push(make_pair(here.first * 2, here.second + 1));
        }
        if (here.first * 10 + 1 <= b) {
            q.push(make_pair(here.first * 10 + 1, here.second + 1));
        }
    }
    return -1;
}

void solve() {
    cout << bfs() << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}