#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> buildings;

void input() {
	cin >> n;
    buildings.resize(n);
    for (int i = 0; i < n; i++) cin >> buildings[i];
}

int getSecondBiggestNumber(int left, int right) {
    int firstIndex = buildings[left] > buildings[left + 1]? left: left + 1;
    int secondIndex = buildings[left] < buildings[left + 1]? left: left + 1;
    
    for (int i = left + 2; i <= right; i++) {
    	if (buildings[firstIndex] < buildings[i]) {
        	secondIndex = firstIndex;
            firstIndex = i;
        }
        else if (buildings[secondIndex] < buildings[i]) {
        	secondIndex = i;
        }
    }
    return secondIndex;
}

int solve() {
	int result = 0;
    for (int i = 0; i < n - 4; i++) {
    	int here = getSecondBiggestNumber(i, i + 4);
        int value = buildings[i + 2] - buildings[here];
        
        if (value > 0) {
        	result += value;
            i += 2;
        }
    }
    return result;
}

int main(void) {
	for (int i = 1; i <= 10; i++) {
    	input();
        int result = solve();
        cout << "#" << i << " ";
        cout << result << "\n";
    }
}