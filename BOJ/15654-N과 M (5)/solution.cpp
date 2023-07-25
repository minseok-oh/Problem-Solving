#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
vector<bool> visited;

void input() {
    cin >> n >> m;
    v.resize(n); visited.resize(n, false);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
}

vector<int> here;
void brute_force() {
    if (here.size() == m) {
        for (auto a: here) cout << v[a] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            here.push_back(i); visited[i] = true;
            brute_force();
            here.pop_back(); visited[i] = false;
        }
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    brute_force();
    return 0;
}