#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> cards;

void input(){
	cin >> n;

	cards.resize(n);
	for(int i = 0; i < n; i++) cin >> cards[i];
	sort(cards.begin(), cards.end());

	cin >> m;
}

void solve(){
	int here;
	for(int i = 0; i < m; i++){
		cin >> here;
		cout << upper_bound(cards.begin(), cards.end(), here) 
			- lower_bound(cards.begin(), cards.end(), here) << " "; 
	}
	cout << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}