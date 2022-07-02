#include <bits/stdc++.h>
using namespace std;
int n;
string square[26];
bool visited[26][26] = { false, };

void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> square[i];
	}
}

const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };

vector<int> ans;
void bfs(int y, int x){
	queue<pair<int, int>> q;
	q.push(make_pair(y, x)); visited[y][x] = true;

	int count = 0;
	while(!q.empty()){
		pair<int, int> here = q.front(); q.pop();
		count++;

		for(int i = 0; i < 4; i++){
			pair<int, int> next = 
				make_pair(here.first + y_grad[i], here.second + x_grad[i]);
			if(0 <= next.first && next.first < n && 0 <= next.second && next.second < n){
				if(square[next.first][next.second] == '1' && !visited[next.first][next.second]){
					q.push(next);
					visited[next.first][next.second] = true;
				}
			}
		}
	}
	ans.push_back(count);
}

void bfs_all(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(square[i][j] == '1' && !visited[i][j]){
				bfs(i, j);
			}
		}
	}
}

void solve(){
	bfs_all();

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(int count: ans) cout << count << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}