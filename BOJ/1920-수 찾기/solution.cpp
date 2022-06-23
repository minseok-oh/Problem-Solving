#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> A;

void input(){
	cin >> n;

	A.resize(n);
	for(int i = 0; i < n; i++) cin >> A[i];
	sort(A.begin(), A.end());
}

void solve(){
	cin >> m;

	int here_value;
	for(int i = 0; i < m; i++){
		cin >> here_value;
		int here = lower_bound(A.begin(), A.end(), here_value) - A.begin();
		if(here >= n){
			cout << "0\n";
			continue;
		}

		if(A[here] != here_value) cout << "0\n";
		else cout << "1\n";
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}