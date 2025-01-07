#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[101];
string key;
bool keySet[26];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    cin >> key;
}

void init() {
    if (key == "0") return;
    for (int i = 0; key[i]; i++) {
        keySet[key[i] - 'a'] = true;
    }
}

void destroy() {
    for (int i = 0; i < 26; i++) {
        keySet[i] = false;    
    }
    
    for (int i = 0; i < n; i++) {
        board[i].clear();
    }
}

const int y_grad[4] = { -1, 0, 0, 1 };
const int x_grad[4] = { 0, -1, 1, 0 };

void solve() {
    queue<pair<int, int>> q;
    bool visited[101][101] = {false};
    multimap<char, pair<int, int>> block;
    
    for (int i = 0; i < n; i++) {
        char c = board[i][0];
        if (c == '.' || ('a' <= c && c <= 'z') || c == '$') {
            q.push(make_pair(i, 0));
            visited[i][0] = true;
        }
        else if ('A' <= c && c <= 'Z') {
            if (keySet[c - 'A']) {
                q.push(make_pair(i, 0));
                visited[i][0] = true;
            }
            else {
                block.insert({c, make_pair(i, 0)});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        char c = board[i][m - 1];
        if (c == '.' || ('a' <= c && c <= 'z') || c == '$') {
            q.push(make_pair(i, m - 1));
            visited[i][m - 1] = true;
        }
        else if ('A' <= c && c <= 'Z') {
            if (keySet[c - 'A']) {
                q.push(make_pair(i, m - 1));
                visited[i][m - 1] = true;
            }
            else {
                block.insert({c, make_pair(i, m - 1)});
            }
        }
    }
    
    for (int i = 1; i < m - 1; i++) {
        char c = board[0][i];
        if (c == '.' || ('a' <= c && c <= 'z') || c == '$') {
            q.push(make_pair(0, i));
            visited[0][i] = true;
        }
        else if ('A' <= c && c <= 'Z') {
            if (keySet[c - 'A']) {
                q.push(make_pair(0, i));
                visited[0][i] = true;
            }
            else {
                block.insert({c, make_pair(0, i)});
            }
        }
    }
    for (int i = 1; i < m - 1; i++) {
        char c = board[n - 1][i];
        if (c == '.' || ('a' <= c && c <= 'z') || c == '$') {
            q.push(make_pair(n - 1, i));
            visited[n - 1][i] = true;
        }
        else if ('A' <= c && c <= 'Z') {
            if (keySet[c - 'A']) {
                q.push(make_pair(n - 1, i));
                visited[n - 1][i] = true;
            }
            else {
                block.insert({c, make_pair(n - 1, i)});
            }
        }
    }
    
    int answer = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        
        char cc = board[cur.first][cur.second];
        if (cc == '$') answer++;
        if ('a' <= cc && cc <= 'z' && !keySet[cc - 'a']) {
            keySet[cc - 'a'] = true;
            
            auto range = block.equal_range(cc - 'a' + 'A');
            for (auto itr = range.first; itr != range.second; ++itr) {
                q.push(itr->second);
                visited[itr->second.first][itr->second.second] = true;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = make_pair(cur.first + y_grad[i], cur.second + x_grad[i]);
            
            if (next.first < 0 || next.first >= n) continue;
            else if (next.second < 0 || next.second >= m) continue;
            else if (visited[next.first][next.second]) continue;
            
            char c = board[next.first][next.second];
            if (c == '.' || ('a' <= c && c <= 'z') || c == '$') {
                q.push(next);
                visited[next.first][next.second] = true;
            }
            else if ('A' <= c && c <= 'Z') {
                if (keySet[c - 'A']) {
                    q.push(next);
                    visited[next.first][next.second] = true;
                }
                else {
                    block.insert({c, next});
                }
            }
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    
    while (t--) {
        input();
        init();
        solve();
        destroy();
    }
    return 0;
}