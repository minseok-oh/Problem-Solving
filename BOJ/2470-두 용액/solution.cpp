#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> liquids;

void input(){
	cin >> n;

	liquids.resize(n);
	for(int i = 0; i < n; i++) cin >> liquids[i];
	sort(liquids.begin(), liquids.end());
}

void solve(){
	long long ans = 2000000001;
	int first_value, second_value;
	for(int i = 0; i < n; i++){
		long long spot = -1 * liquids[i];
		int here = lower_bound(liquids.begin(), liquids.end(), spot) - liquids.begin();

		long long temp_sum;
		if(here > 0 && i != here - 1){
			temp_sum = abs(liquids[i] + liquids[here - 1]);
			if(ans > temp_sum){
				ans = temp_sum;
				first_value = min(liquids[i], liquids[here - 1]);
				second_value = max(liquids[i], liquids[here - 1]);
			}
		}
		if(here < n && i != here){
			temp_sum = abs(liquids[i] + liquids[here]);
			if(ans > temp_sum){
				ans = temp_sum;
				first_value = min(liquids[i], liquids[here]);
				second_value = max(liquids[i], liquids[here]);
			}
		}
	}
	cout << first_value << " " << second_value << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}