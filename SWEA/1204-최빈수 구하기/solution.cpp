#include <bits/stdc++.h>
using namespace std;

int getMode() {
	int student, result = 0;
    int scores[101] = { 0, };
    
    for (int i = 0; i < 1000; i++) {
    	cin >> student;
        scores[student]++;
    }
    
    for (int i = 0; i < 101; i++) {
    	result = scores[result] > scores[i]? result: i;
    }
    return result;
}

int main(void) {
	cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
    	int caseNumber;
        cin >> caseNumber;    
        cout << "#" << caseNumber << " ";
        cout << getMode() << "\n";
    }
}