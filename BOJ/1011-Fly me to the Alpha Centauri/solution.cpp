#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> dist;

void input() {
    cin >> t;

    int x, y;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        dist.push_back(y - x);
    }
}

int solve(int i) {
    double root = sqrt(dist[i]);
    int here = floor(root);

    if (dist[i] == here * here) {
        return 2 * here - 1;
    } else if ((root - here) <= 0.5) {
        return 2 * here;
    } else {
        return 2 * here + 1;
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    for (int i = 0; i < t; i++) {
        cout << solve(i) << "\n";
    }
    return 0;
}