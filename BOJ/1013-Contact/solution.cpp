#include <bits/stdc++.h>
using namespace std;
int t;
vector<short> graph[7][3];
vector<string> waves;

void init() {
    graph[0][0].push_back(5); graph[0][1].push_back(1);
    graph[1][0].push_back(2);
    graph[2][0].push_back(3);
    graph[3][0].push_back(3); graph[3][1].push_back(4);
    graph[4][1].push_back(4); graph[4][2].push_back(0);
    graph[5][1].push_back(6);
    graph[6][2].push_back(0);
}

void input() {
    cin >> t;
    
    string wave;
    for (int i = 0; i < t; i++) {
        cin >> wave;
        waves.push_back(wave);    
    }
}

bool solve(const string& wave) {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        pair<int, int> here = q.front(); q.pop();
        if (here.second == wave.size()) {
            if (here.first == 4 || here.first == 6) return true;
        } 

        for (int node: graph[here.first][wave[here.second] - '0']) {
            q.push(make_pair(node, here.second + 1));
        }

        for (int node: graph[here.first][2]) {
            q.push(make_pair(node, here.second));
        }
    }
    return false;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    input();
    for (int i = 0; i < t; i++) {
        bool res = solve(waves[i]);
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}