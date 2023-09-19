#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> graph[123457];

typedef struct island {
    char t;
    int a, p;
} Island;
Island islands[123457];

void input() {
    cin >> n;

    Island island;
    for (int i = 2; i <= n; i++) {
        cin >> island.t >> island.a >> island.p;

        islands[i] = island;
        if (islands[i].t == 'W') islands[i].a = -1 * islands[i].a;

        graph[island.p].push_back(i);
    }
}

long long solve(int here) {
    long long res = 0;
    for (int next: graph[here]) {
        res += solve(next);
    }
    res += islands[here].a;
    if (res < 0) res = 0;

    return res;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    cout << solve(1) << "\n";
    return 0;
}