#include <bits/stdc++.h>
using namespace std;
int n, e, u, v;
vector<pair<int, int>> graph[801];

void input() {
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    cin >> u >> v;   
}

vector<int> getShortestPathFromNode(int node) {
    vector<int> dist(n + 1);
    vector<bool> visited(n + 1);
    priority_queue<pair<int, int>> pq;
    
    for (int i = 1; i <= n; i++) {
        dist[i] = 987654321;
        visited[i] = false;
    }
    
    dist[node] = 0;
    pq.push(make_pair(0, node));
    
    while (!pq.empty()) {
        pair<int, int> here = pq.top(); pq.pop();
        if (visited[here.second]) continue;
        visited[here.second] = true;
        
        for (pair<int, int> edge: graph[here.second]) {
            if (dist[edge.first] > - here.first + edge.second) {
                dist[edge.first] = - here.first + edge.second;
                pq.push(make_pair(- dist[edge.first], edge.first));
            }
        }    
    }
    return dist;
}

long getAnswer(
    const vector<int>& dist1, const vector<int>& dist2,
    const vector<int>& dist3
    ) {
    
    int answer1 = dist1[u] + dist2[v] + dist3[n];
    if (dist1[u] == 987654321 || dist3[n] == 987654321) {
        answer1 = 987654321;
    }
    int answer2 = dist1[v] + dist3[u] + dist2[n];
    if (dist1[v] == 987654321 || dist2[n] == 987654321) {
        answer2 = 987654321;
    }
    
    return min(answer1, answer2);
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    
    vector<int> shortestPathFromStart = getShortestPathFromNode(1);
    vector<int> shortestPathFromU = getShortestPathFromNode(u);
    vector<int> shortestPathFromV = getShortestPathFromNode(v);
    
    int result = getAnswer(shortestPathFromStart, shortestPathFromU, 
        shortestPathFromV);
    if (result == 987654321) result = -1;
    cout << result << "\n";
    return 0;
}