#include <bits/stdc++.h>
using namespace std;
int n, m;
int A[20001], B[20001];

void input(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < m; i++) cin >> B[i];
}

void solve(){
	sort(B, B + m);

	int sum = 0;
	for(int i = 0; i < n; i++){
		int here = lower_bound(B, B + m, A[i]) - B;
		sum += here;
	}
	cout << sum << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		input();
		solve();
	}
	return 0;
}