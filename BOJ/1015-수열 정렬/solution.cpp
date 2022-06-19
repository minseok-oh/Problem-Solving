#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> P, ans;

void input(){
	cin >> n;

	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		P.push_back(temp);
	}
	ans.resize(n);
}

void solve(){
	int minValue, minIndex;
	vector<bool> used(n, false);
	for(int i = 0; i < n; i++){
		minValue = 1001;
		for(int j = 0; j < n; j++){
			if(used[j]) continue;
			if(minValue > P[j]){
				minValue = P[j];
				minIndex = j;	
			}
		}
		ans[minIndex] = i;
		used[minIndex] = true;
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	for(int p: ans) cout << p << " ";
	cout << "\n";
	return 0;
}