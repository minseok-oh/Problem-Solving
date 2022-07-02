#include <bits/stdc++.h>
using namespace std;
int n, m, v;
bool graph[1001][1001] = { false, };

void input(){
	cin >> n >> m >> v;

	int first, second;
	for(int i = 0; i < m; i++){
		cin >> first >> second;
		graph[first][second] = graph[second][first] = true;
	}
}

bool dfs_visited[1001] = { false, };
void dfs(int here){
	dfs_visited[here] = true;
	cout << here << " ";

	for(int i = 1; i <= n; i++){
		if(graph[here][i] && !dfs_visited[i]){
			dfs(i);
		}
	}
}

void bfs(){
	queue<int> q;
	bool bfs_visited[1001] = { false, };

	q.push(v); bfs_visited[v] = true;
	while(!q.empty()){
		int here = q.front(); q.pop();
		cout << here << " ";

		for(int i = 1; i <= n; i++){
			if(graph[here][i] && !bfs_visited[i]){
				q.push(i);
				bfs_visited[i] = true;
			}
		}
	}
}

void solve(){
	dfs(v);
	cout << "\n";
	bfs();
	cout << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}