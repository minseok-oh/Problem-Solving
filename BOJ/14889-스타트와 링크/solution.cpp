#include <bits/stdc++.h>
using namespace std;
int n, board[21][21];
int ret = 987654321;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
}

vector<int> start;
bool visited[21] = { false, };
void solve(int here) {
    if (start.size() == n / 2) {
        vector<int> link;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) link.push_back(i);
        }

        int start_ret = 0, link_ret = 0;
        for (int i = 0; i < start.size(); i++) {
            for (int j = 0; j < start.size(); j++) {
                start_ret += board[start[i]][start[j]];
                link_ret += board[link[i]][link[j]];
            }
        }
        ret = min(ret, abs(start_ret - link_ret));
    }

    for (int i = here; i < n; i++) {
        start.push_back(i); visited[i] = true;
        solve(i + 1);
        start.pop_back(); visited[i] = false;
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve(0);
    cout << ret << "\n";
    return 0;
}