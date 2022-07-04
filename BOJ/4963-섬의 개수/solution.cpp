#include <bits/stdc++.h>
using namespace std;
int w, h;
bool field[51][51];
bool visited[51][51];

void input(){
	cin >> w >> h;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> field[i][j];
			visited[i][j] = false;
		}
	}
}

const int y_grad[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int x_grad[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void dfs(int y, int x){
	if(visited[y][x]) return ;
	visited[y][x] = true;

	for(int i = 0; i < 8; i++){
		int next_y = y + y_grad[i], next_x = x + x_grad[i];
		if(0 <= next_y && next_y < h && 0 <= next_x && next_x < w){
			if(field[next_y][next_x]){
				dfs(next_y, next_x);
			}
		}
	}
}

void solve(){
	input();
	while(w || h){
		int ans = 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(field[i][j] && !visited[i][j]){
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
		input();
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	solve();
	return 0;
}