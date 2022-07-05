#include <bits/stdc++.h>
using namespace std;
int r, c, sheep = 0, wolf = 0;
string field[251];
bool visited[251][251] = { false, };

void input(){
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		cin >> field[i];
	}
}

const int y_grad[4] = { -1, 0, 0, 1 };
const int x_grad[4] = { 0, -1, 1, 0 };

void bfs(int y, int x){
	queue<pair<int, int>> q;
	q.push(make_pair(y, x)); visited[y][x] = true;

	int here_sheep = 0, here_wolf = 0;
	while(!q.empty()){
		pair<int, int> here = q.front(); q.pop();
		if(field[here.first][here.second] == 'o') here_sheep++;
		else if(field[here.first][here.second] == 'v') here_wolf++;

		for(int i = 0; i < 4; i++){
			pair<int, int> next = make_pair(here.first + y_grad[i], here.second + x_grad[i]);
			if(0 <= next.first && next.first < r && 0 <= next.second && next.second < c){
				if(field[next.first][next.second] != '#' && !visited[next.first][next.second]){
					q.push(next);
					visited[next.first][next.second] = true;
				}
			}
		}
	}

	if(here_wolf >= here_sheep) wolf += here_wolf;
	else sheep += here_sheep;
}

void solve(){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(field[i][j] != '#' && !visited[i][j]){
				bfs(i, j);
			}
		}
	}
	cout << sheep << " " << wolf << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}