#include <bits/stdc++.h>
using namespace std;
int k;
string gears[4];
vector<pair<int, int>> rotation;

void input() {
    for (int i = 0; i < 4; i++) cin >> gears[i];

    cin >> k;
    rotation.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> rotation[i].first >> rotation[i].second;
    }
}

void leftRotate(int idx) {
    char here = gears[idx][0];
    for (int i = 0; i < 7; i++) {
        gears[idx][i] = gears[idx][i + 1];
    }
    gears[idx][7] = here;
}

void rightRotate(int idx) {
    char here = gears[idx][7];
    for(int i = 7; i >= 1; i--) {
        gears[idx][i] = gears[idx][i - 1];
    }
    gears[idx][0] = here;
}

void solve() {
    for (int i = 0; i < k; i++) {
        short op[4] = { 0, };
        short here_gear = rotation[i].first - 1;
        op[here_gear] = rotation[i].second;
        for (int j = here_gear + 1; j < 4; j++) {
            if (gears[j - 1][2] == gears[j][6]) break;
            op[j] = -1 * op[j - 1];
        }
        for (int j = here_gear - 1; j >= 0; j--) {
            if (gears[j][2] == gears[j + 1][6]) break;
            op[j] = -1 * op[j + 1];
        }

        for (int j = 0; j < 4; j++) {
            if (op[j] == 1) {
                rightRotate(j);
            } else if (op[j] == -1) {
                leftRotate(j);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (gears[i][0] == '1') {
            res += pow(2, i);
        }
    }
    cout << res << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}