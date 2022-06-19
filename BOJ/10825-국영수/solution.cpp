#include <bits/stdc++.h>
using namespace std;
int n;

typedef struct _student{
	string name;
	int ko, en, ma;
}student;

vector<student> school;
void input(){
	cin >> n;

	student temp;
	for(int i = 0; i < n; i++){
		cin >> temp.name >> temp.ko >> temp.en >> temp.ma;
		school.push_back(temp);
	}
}

bool comp(const student s1, const student s2){
	if(s1.ko > s2.ko) return true;
	else if(s1.ko < s2.ko) return false;
	else{
		if(s1.en < s2.en) return true;
		else if(s1.en > s2.en) return false;
		else{
			if(s1.ma > s2.ma) return true;
			else if(s1.ma < s2.ma) return false;
			else{
				return s1.name < s2.name;
			}
		}
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	sort(school.begin(), school.end(), comp);
	for(student st: school) cout << st.name << "\n";
	return 0;
}