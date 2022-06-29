#include <bits/stdc++.h>
using namespace std;
int n;
string str;

void input(){
	cin >> n >> str;
}

void solve(){
	int left = 0, right = 0, res = 1;
	vector<int> count_alp(26, 0);

	int count = 1;
	count_alp[str[left] - 'a'] = 1;
	while(str[left] && str[right]){
		if(count > n){
			count_alp[str[left] - 'a']--;
			if(count_alp[str[left] - 'a'] == 0){
				count--;
			}
			left++;
		}
		else{
			right++;
			if(!str[right]) break;

			if(count_alp[str[right] - 'a'] == 0){
				count++;
			}
			count_alp[str[right] - 'a']++;
		}

		if(count <= n){
			res = max(res, right - left + 1);
		}
	}
	cout << res << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}