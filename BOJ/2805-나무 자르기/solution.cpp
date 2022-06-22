#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> trees;

void input(){
	cin >> n >> m;

	trees.resize(n);
	for(int i = 0; i < n; i++) cin >> trees[i];
}

long long sum_tree(int cut){
	long long sum = 0;
	for(int tree: trees){
		if(tree > cut) sum += (tree - cut);
	}
	return sum;
}

void solve(){
	int left = 0, right = 1000000000;
	while(left <= right){
		int mid = (left + right) / 2;

		long long here = sum_tree(mid);
		if(here >= m){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	} 
	cout << right << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}