#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> students;
bool checked[100001] = { false, };
bool visited[100001] = { false, };

void input() {
    cin >> n;
    students.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> students[i];
    }
}

void init() {
    students.clear();
    memset(checked, false, sizeof(checked));
    memset(visited, false, sizeof(visited));
}

void createCycle(int current) {
    vector<int> orders;
    
    int next = current;
    while (!visited[next]) {
        visited[next] = true;
        orders.push_back(next);
        next = students[next];
    }
    
    bool ok = false;
    for (int i = 0; i < orders.size(); i++) {
        if (ok) {
            checked[orders[i]] = true;
        }
        else {
            if (next == orders[i]) {
                ok = true;
                checked[next] = true;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            createCycle(i);
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (!checked[i]) answer++;
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--) {
        init();
        input();
        solve();
    }
    return 0;
}