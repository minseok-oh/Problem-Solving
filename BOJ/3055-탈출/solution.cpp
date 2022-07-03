#include <bits/stdc++.h>
using namespace std;
int r, c;
string forest[51];

void input(){
	cin >> r >> c;
	for(int i = 0; i < r; i++) cin >> forest[i];
}

const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };

struct node{
	int y, x;
	char c;
};

int count_minutes(){
	queue<node> q;
	int visited[51][51] = { 0, };

	char water[51][51];
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			water[i][j] = forest[i][j];
			if(forest[i][j] == '*') q.push({ i, j, '*' });
		}
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(forest[i][j] == 'S'){
				q.push({ i, j, 'S' });
				visited[i][j] = 1;
			}
		}
	}

	while(!q.empty()){
		node here = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			node next = { here.y + y_grad[i], here.x + x_grad[i], here.c };
			if(next.y < 0 || next.y >= r || next.x < 0 || next.x >= c) continue;

			if(next.c == '*'){
				if(water[next.y][next.x] == '.'){
					water[next.y][next.x] = '*';
					q.push(next);
				}
			}
			else{
				if(water[next.y][next.x] == '*' || forest[next.y][next.x] == 'X') continue;

				if(forest[next.y][next.x] == 'D') return visited[here.y][here.x];
				else if(forest[next.y][next.x] == '.'){
					forest[next.y][next.x] = 'S';
					visited[next.y][next.x] = visited[here.y][here.x] + 1;
					q.push(next);
				}
			}
		}
	}
	return -1;
}

void solve(){
	int ans = count_minutes();
	if(ans == -1) cout << "KAKTUS\n";
	else cout << ans << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}