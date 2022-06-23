#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<int> house;

void input(){
	cin >> n >> c;

	house.resize(n);
	for(int i = 0; i < n; i++) cin >> house[i];
	sort(house.begin(), house.end());
}

int set_wifi(int dist){
	int here = 0, count = 1;
	for(int i = 1; i < n; i++){
		if(house[i] - house[here] > dist){
			here = i;
			count++;
		}
	}
	return count;
}

int binary_search(){
	int left = 0, right = house[n - 1] - house[0];
	while(left <= right){
		int mid = (left + right) / 2;

		int here = set_wifi(mid);
		if(here < c){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return left;
}

void solve(){
	int ans = binary_search();
	cout << ans << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}