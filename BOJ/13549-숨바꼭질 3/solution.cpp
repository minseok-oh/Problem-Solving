#include <bits/stdc++.h>
using namespace std;
int n, k;
const int MAX = 100001;

void input() {
    cin >> n >> k;
}

int dist[MAX];
int dijkstra(int start, int end) {
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < MAX; i++) dist[i] = 987654321;

    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int time = -pq.top().first;
        int here = pq.top().second; pq.pop();
        if (here == end) return time;
        if (time > dist[here]) continue;

        if (here + 1 < MAX && dist[here + 1] > dist[here] + 1) {
            dist[here + 1] = dist[here] + 1;
            pq.push(make_pair(-time-1, here + 1));
        }
        if (here - 1 >= 0 && dist[here - 1] > dist[here] + 1) {
            dist[here - 1] = dist[here] + 1;
            pq.push(make_pair(-time-1, here - 1));
        }
        if (here * 2 < MAX && dist[here * 2] > dist[here]) {
            dist[here * 2] = dist[here];
            pq.push(make_pair(-time, here * 2));
        }
    }
    return dist[end];
}

void solve() {
    cout << dijkstra(n, k) << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}