#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> words;

void input(){
	cin >> n;
	words.resize(n);
	for(int i = 0; i < n; i++) cin >> words[i];
}

bool cmp(const string s1, const string s2){
	if(s1.size() != s2.size()) return s1.size() < s2.size();
	return s1 < s2;
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	sort(words.begin(), words.end(), cmp);
	for(int i = 0; i < n; i++){
		cout << words[i] << "\n";
		for(;i < n - 1 && words[i] == words[i + 1]; i++);
	}
	return 0;
}