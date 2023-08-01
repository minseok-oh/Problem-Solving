#include <bits/stdc++.h>
using namespace std;
int n, m, ladder[101], snake[101];

void init() {
    for (int i = 0; i < 101; i++) {
        ladder[i] = snake[i] = -1;
    }
}

void input() {
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ladder[x] = y;
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        snake[x] = y;
    }
}

int solve() {
    queue<pair<int, int>> q;
    bool visited[101] = { false, };
    q.push(make_pair(1, 0)); visited[1] = true;

    while (!q.empty()) {
        int here = q.front().first;
        int count = q.front().second; q.pop();
        if (here == 100) return count;

        bool ok = true;
        for (int i = 1; i <= 6; i++) {
            int next = here + i;
            if (next > 100) continue;

            bool ok = true;
            if (ladder[next] != -1) {
                q.push(make_pair(ladder[next], count + 1));
                visited[next] = visited[ladder[next]] = true; ok = false;
            }
            if (snake[next] != -1) {
                q.push(make_pair(snake[next], count + 1));
                visited[next] = visited[snake[next]] = true; ok = false;
            }

            if (ok && !visited[next]) {
                q.push(make_pair(next, count + 1));
                visited[next] = true;
            }
        }
    }
    return -1;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    input();
    cout << solve() << "\n";
    return 0;
}