#include <bits/stdc++.h>
using namespace std;
int n, m;
set<string> names;

void input(){
	cin >> n >> m;

	string name;
	for(int i = 0; i < n; i++){
		cin >> name;
		names.insert(name);
	}
}

void solve(){
	string name;
	vector<string> ans;
	for(int i = 0; i < m; i++){
		cin >> name;
		if(names.find(name) != names.end()){
			ans.push_back(name);
		}
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for(string name: ans) cout << name << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}