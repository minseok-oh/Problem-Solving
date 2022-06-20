#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> files; 

void input(){
	cin >> n;

	for(int i = 0; i < n; i++){
		bool flag = false;
		string name, ext;

		cin >> name;
		for(int j = 0; name[j]; j++){
			if(flag) ext += name[j];
			if(name[j] == '.') flag = true;
		}

		auto iter = files.find(ext);
		if(iter != files.end()) iter->second++;
		else files.insert(make_pair(ext, 1));
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	for(auto temp: files) cout << temp.first  << " " << temp.second << "\n";
	return 0;
}