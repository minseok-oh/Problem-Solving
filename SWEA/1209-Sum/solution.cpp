#include <bits/stdc++.h>
using namespace std;
int board[100][100];

void input() {
    int count;
    cin >> count;
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cin >> board[i][j];
        }
    }
}

int getLineSum(int line) {
    int col_result = 0, row_result = 0;
    for (int i = 0; i < 100; i++) {
        col_result += board[line][i];
        row_result += board[i][line];
    }
    return max(col_result, row_result);
}

int getGreatestSum() {
    int result = -1;
    int slash = 0, back_slash = 0;
    
    for (int i = 0; i < 100; i++) {
        result = max(result, getLineSum(i));
        slash += board[i][99 - i];
        back_slash += board[i][i];
    }
    result = max(result, slash);
    result = max(result, back_slash);
    return result;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 0; i < 10; i++) {
        input();
        int result = getGreatestSum();
        
        cout << "#" << i + 1 << " ";
        cout << result << "\n";
    }
    return 0;
}