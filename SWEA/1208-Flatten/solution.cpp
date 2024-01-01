#include <bits/stdc++.h>
using namespace std;
int dump;
int heights[101] = { 0, };

void init() {
    for (int i = 1; i < 101; i++) {
        heights[i] = 0;
    }
}

void input() {
    cin >> dump;
    
    int height;
    for (int i = 0; i < 100; i++) {
        cin >> height;
        heights[height]++;
    }
}

int solve() {
    int left = 1, right = 100;
    for (int i = 0; i < dump; i++) {
        while (heights[left] == 0) left++;
        while (heights[right] == 0) right--;
        
        heights[left] -= 1;
        heights[left + 1] += 1;
        
        heights[right] -= 1;
        heights[right - 1] += 1;
    }
    
    while (heights[left] == 0) left++;
    while (heights[right] == 0) right--;
    return right - left;
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        init();
        input();
        
        cout << "#" << i + 1 << " ";
        cout << solve() << "\n";
    }
    return 0;
}