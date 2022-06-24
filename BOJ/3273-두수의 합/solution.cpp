#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> a;

void input(){
	cin >> n;

	a.resize(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	cin >> x;
}

void solve(){
	int count = 0;
	for(int i = 0; i < n; i++){
		int here = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
		if(i < here && a[here] == x - a[i]) count++;
	}
	cout << count << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}
