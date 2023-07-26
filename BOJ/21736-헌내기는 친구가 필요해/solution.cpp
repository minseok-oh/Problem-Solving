#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> campus;

void input() {
    cin >> n >> m;

    campus.resize(n);
    for (int i = 0; i < n; i++) cin >> campus[i];
}

const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };
void bfs() {
    queue<pair<int, int>> q;
    bool visited[601][601] = { false, };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (campus[i][j] == 'I') {
                q.push(make_pair(i, j)); visited[i][j] = true;
                break;
            }
        }
        if (!q.empty()) break;
    }

    int res = 0;
    while(!q.empty()) {
        pair<int, int> here = q.front(); q.pop();
        if (campus[here.first][here.second] == 'P') res++;

        for (int i = 0; i < 4; i++) {
            pair<int, int> next = make_pair(
                here.first + y_grad[i],
                here.second + x_grad[i]
            );

            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
            if (!visited[next.first][next.second] && campus[next.first][next.second] != 'X') {
                q.push(next);
                visited[next.first][next.second] = true;
            }
        }
    }

    if (res == 0) cout << "TT\n";
    else cout << res << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    bfs();
    return 0;
}