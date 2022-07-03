#include <bits/stdc++.h>
using namespace std;
int n, k;
const int Max = 100000;

void input(){
	cin >> n >> k;
}

int bfs(){
	queue<int> q;
	int visited[100001] = { 0, };

	q.push(n); visited[n] = 1;
	while(!q.empty()){
		int here = q.front(); q.pop();
		if(here == k) return visited[here] - 1;

		if(here - 1 >= 0 && !visited[here - 1]){
			q.push(here - 1);
			visited[here - 1] = visited[here] + 1;
		}
		if(here + 1 <= Max && !visited[here + 1]){
			q.push(here + 1);
			visited[here + 1] = visited[here] + 1;
		}
		if(here * 2 <= Max && !visited[here * 2]){
			q.push(here * 2);
			visited[here * 2] = visited[here] + 1;
		}
	}
	return -1;
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