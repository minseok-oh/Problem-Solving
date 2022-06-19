#include <bits/stdc++.h>
using namespace std;
int n, len = -1;
vector<int> point[5001];

void input(){
	cin >> n;

	int x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		point[y].push_back(x);
		len = max(len, y);
	}
	for(auto& a: point) sort(a.begin(), a.end());
}

void solve(){
	long long ret = 0;
	for(int i = 1; i <= len; i++){
		if(point[i].empty()) continue;
		
		int point_len = point[i].size() - 1;
		ret += (point[i][1] - point[i][0]);
		for(int j = 1; j < point_len; j++) 
			ret += min(point[i][j] - point[i][j - 1], point[i][j + 1] - point[i][j]);
		ret += (point[i][point_len] - point[i][point_len - 1]);
	}
	cout << ret << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}