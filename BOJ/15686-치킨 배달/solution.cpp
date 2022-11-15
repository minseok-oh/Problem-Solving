#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 987654321;
vector<pair<int, int>> chicken, house, selectedChicken;

void input() {
    cin >> n >> m;

    int number;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> number;
            if (number == 1) {
                house.push_back(make_pair(i, j));
            } else if (number == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
}

int calDistance() {
    int res = 0;
    for (pair<int, int> a: house) {
        int minDist = 987654321;
        for (pair<int, int> c: selectedChicken) {
            minDist = min(minDist, abs(a.first - c.first) + abs(a.second - c.second));
        }
        res += minDist;
    }
    return res;
}

void selectChicken(int here) {
    if (selectedChicken.size() == m) {
        ans = min(ans, calDistance());
        return;
    }

    for(int i = here; i < chicken.size(); i++) {
        selectedChicken.push_back(chicken[i]);
        selectChicken(i + 1);
        selectedChicken.pop_back();
    }
}

void solve() {
    selectChicken(0);
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}