#include <bits/stdc++.h>
using namespace std;
int n, m, res = 0;
short lab[9][9];

void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> lab[i][j];
		}
	}
}

int count_safety_area(const short temp_lab[9][9]){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(temp_lab[i][j] == 0){
				ans++;
			}
		}
	}
	return ans;
}

const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };

int bfs(){
	queue<pair<int, int>> q;

	short temp_lab[9][9];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			temp_lab[i][j] = lab[i][j];
			if(lab[i][j] == 2){
				q.push(make_pair(i, j));
			}
		}
	}

	while(!q.empty()){
		pair<int, int> here = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			pair<int, int> next = 
				make_pair(here.first + y_grad[i], here.second + x_grad[i]);
			
			if(0 < next.first && next.first <= n && 0 < next.second && next.second <= m){
				if(temp_lab[next.first][next.second] == 0){
					q.push(next);
					temp_lab[next.first][next.second] = 2;
				}
			}
		}
	}

	return count_safety_area(temp_lab);
}

void make_walls(int count){
	if(count == 3){
		res = max(res, bfs());
		return ;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(lab[i][j] == 0){
				lab[i][j] = 1;
				make_walls(count + 1);
				lab[i][j] = 0;
			}
		}
	}
}

void solve(){
	make_walls(0);
	cout << res << "\n";
}

int main(){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}