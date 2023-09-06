#include <bits/stdc++.h>
using namespace std;
long long n, sum_x, sum_y;
vector<int> x, y;

void input() {
    cin >> n;
    x.resize(n); y.resize(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];    
}

void init() {
    sum_x = 0, sum_y = 0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
    }
}

double getDistance(long long here_x, long long here_y) {
    return sqrt((double)(here_x * here_x) + (double)(here_y * here_y));
}

vector<int> visited;
double bruteForce(int here) {
    if (visited.size() == n / 2) {
        long long ret_x = 0, ret_y = 0;
        for (auto index: visited) {
            ret_x += x[index];
            ret_y += y[index];
        }
        return getDistance(sum_x - 2 * ret_x, sum_y - 2 * ret_y);
    }

    double ret = 987654321;
    for (int i = here + 1; i < n; i++) {
        visited.push_back(i);
        ret = min(ret, bruteForce(i));
        visited.pop_back();
    }
    return ret;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        input();
        init();
        cout << bruteForce(-1) << "\n";;
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    cout << fixed;
    cout.precision(6);

    solve();
    return 0;
}