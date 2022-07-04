#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool field[51][51] = { false, };
bool visited[51][51] = { false,  };

void input(){
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			field[i][j] = false;
			visited[i][j] = false;
		}
	}

	int y, x;
	for(int i = 0; i < k; i++){
		cin >> y >> x;
		field[y][x] = true;
	}	
}

const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };

void dfs(int y, int x){
	if(visited[y][x]) return ;
	visited[y][x] = true;

	for(int i = 0; i < 4; i++){
		int next_y = y + y_grad[i], next_x = x + x_grad[i];
		if(0 <= next_y && next_y < n && 0 <= next_x && next_x < m){
			if(field[next_y][next_x]){
				dfs(next_y, next_x);
			}
		}
	}
}

void solve(){
	int t;
	cin >> t;
	while(t--){
		input();

		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(field[i][j] && !visited[i][j]){
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	solve();
	return 0;
}