#include <bits/stdc++.h>
using namespace std;
int a, b, c;
bool visited[201][201][201] = { false, };

void input(){
	cin >> a >> b >> c;
}

bool ans[201] = { false, };
void dfs(int A, int B, int C){
	if(visited[A][B][C]) return ;
	visited[A][B][C] = true;

	if(A == 0) ans[C] = true;

	if(b - B <= A) dfs(A - (b - B), b, C);
	else dfs(0, A + B, C);

	if(c - C <= A) dfs(A - (c - C), B, c);
	else dfs(0, B, A + C);
	
	if(c - C <= B) dfs(A , B - (c - C), c);
	else dfs(A, 0, B + C);

	if(a - A <= B) dfs(a, B - (a - A), C);
	else dfs(A + B, 0, C);

	if(b - B <= C) dfs(A, b, C - (b - B));
	else dfs(A, B + C, 0);

	if(a - A <= C) dfs(a, B, C - (a - A));
	else dfs(A + C, B, 0);
}

void solve(){
	dfs(0, 0, c);
	for(int i = 0; i <= c; i++){
		if(ans[i]) cout << i << " ";
	}
	cout << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}