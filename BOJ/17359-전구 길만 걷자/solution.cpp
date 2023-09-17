#include <bits/stdc++.h>
using namespace std;
int n, res = 0;
short lights[11][2] = { 0, };

void input() {
    cin >> n;
    string light;
    for (int i = 0; i < n; i++) {
        cin >> light;
        lights[i][0] = light[0] - '0';
        lights[i][1] = light[light.size() - 1] - '0';

        for (int i = 1; light[i]; i++) {
            if (light[i - 1] != light[i]) res++;
        }
    }
}

vector<int> order;
bool visited[11] = { false, };
int solve() {
    if (order.size() == n) {
        int orderCount = 0;
        for (int i = 1; i < n; i++) {
            if (lights[order[i - 1]][1] != lights[order[i]][0]) orderCount++;
        }
        return orderCount;
    }

    int res = 1001;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true; order.push_back(i);
            res = min(res, solve());
            visited[i] = false; order.pop_back();
        }
    }
    return res;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    cout << res + solve() << "\n";
    return 0;
}