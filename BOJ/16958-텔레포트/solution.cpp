#include <bits/stdc++.h>
using namespace std;
int n, t, m;
vector<pair<int, int>> problems;

typedef struct city {
    int x, y;
} City;

vector<City> cities;
bool isSpecial[1001] = { false, };
int normal2special[1001] = { 0, };

void input() {
    cin >> n >> t;

    int ok;
    City city;
    for (int i = 0; i < n; i++) {
        cin >> ok >> city.x >> city.y;

        if (ok) isSpecial[i] = true;
        cities.push_back(city);
    }

    cin >> m;
    pair<int, int> p;
    for (int i = 0; i < m; i++) {
        cin >> p.first >> p.second;
        problems.push_back(p);
    }
}

int getDistance(City& a, City& b) {
    int dist_r = abs(a.x - b.x);
    int dist_c = abs(a.y - b.y);
    return dist_r + dist_c;
}

void initNormal2Special(int idx) {
    int dist = 987654321;
    for (int i = 0; i < n; i++) {
        if (isSpecial[i]) {
            dist = min(dist, getDistance(cities[idx], cities[i]));
        }
    }
    normal2special[idx] = dist;
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (!isSpecial[i]) {
            initNormal2Special(i);
        }
    }

    for (int i = 0; i < m; i++) {
        int r = problems[i].first - 1, c = problems[i].second - 1;
        int here = getDistance(cities[r], cities[c]);

        if (isSpecial[r] && isSpecial[c]) {
            here = min(here, t);
        }
        else if (isSpecial[r]) {
            here = min(here, normal2special[c] + t);
        }
        else if (isSpecial[c]) {
            here = min(here, normal2special[r] + t);
        }
        else {
            here = min(here, normal2special[r] + normal2special[c] + t);
        }
        cout << here << "\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}