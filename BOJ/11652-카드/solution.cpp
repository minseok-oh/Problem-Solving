#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> cards;

void input(){
	cin >> n;
	cards.resize(n);
	for(int i = 0; i < n; i++) cin >> cards[i];
}

void solve(){
	long long maxValue, maxCount = -1; 
	sort(cards.begin(), cards.end());

	for(int i = 0; i < n; i++){
		int count = upper_bound(cards.begin(), cards.end(), cards[i]) - 
					lower_bound(cards.begin(), cards.end(), cards[i]);
					
		if(maxCount < count){
			maxValue = cards[i];
			maxCount = count;
		}
		i += (count - 1);
	}
	cout << maxValue << "\n";
}

int main(void){
	input();
	solve();
	return 0;
}