#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> liquids;

void input(){
	cin >> n;
	liquids.resize(n);
	for(int i = 0; i < n; i++) cin >> liquids[i];
}

void solve(){
	sort(liquids.begin(), liquids.end());

	vector<int> ans(3);
	long long res = 3000000001;

	for(int i = 0; i < n; i++){
		int left = 0, right = n - 1;
		while(left < right){
			if(left == i){
				left++;
				continue;
			}
			if(right == i){
				right--;
				continue;
			}

			long long here = liquids[left] + liquids[right] + liquids[i];
			if(abs(here) < res){
				ans[0] = i, ans[1] = left, ans[2] = right;
				res = abs(here);
			}

			if(here >= 0){
				right--;
			}
			else{
				left++;
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(int idx: ans){
		cout << liquids[idx] << " ";
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}