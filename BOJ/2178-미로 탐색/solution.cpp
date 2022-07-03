#include <bits/stdc++.h>
using namespace std;
int n, m;
string maze[101];

void input(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> maze[i];
	}
}

const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };

int bfs(){
	queue<pair<int, int>> q;
	int visited[101][101] = { 0, };

	q.push(make_pair(0, 0)); visited[0][0] = 1;
	while(!q.empty()){
		pair<int, int> here = q.front(); q.pop();
		if(here.first == n - 1 && here.second == m - 1) 
			return visited[n - 1][m - 1];

		for(int i = 0; i < 4; i++){
			pair<int, int> next = 
				make_pair(here.first + y_grad[i], here.second + x_grad[i]);
			
			if(0 <= next.first && next.first < n && 0 <= next.second && next.second < m){
				if(maze[next.first][next.second] == '1' && !visited[next.first][next.second]){
					q.push(next);
					visited[next.first][next.second] = visited[here.first][here.second] + 1;
				}
			}
		}
	}
	return 0;
}

void solve(){
	int ans = bfs();
	cout << ans << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}