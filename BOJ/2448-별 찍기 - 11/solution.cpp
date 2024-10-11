#include <bits/stdc++.h>
using namespace std;
int n;
bool board[1024 * 6][1024 * 6] = { false, };

void writeStar(int y, int x) {
    board[y][x + 2] = true;
    board[y + 1][x + 1] = board[y + 1][x + 3] = true;
    for (int i = 0; i < 5; i++) board[y + 2][x + i] = true;
}

void recursive(int y, int x, int size) {
    if (size == 3) {
        writeStar(y, x);
        return ;
    }
    
    int half = size / 2;
    recursive(y + half, x, size / 2);
    recursive(y, x + half, size / 2);
    recursive(y + half, x + size, size / 2);
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) {
            if (!board[i][j]) cout << " ";
            else cout << "*";
        }
        cout << "\n";
    }
}

int main(void) {
    cin >> n;
    
    recursive(0, 0, n);
    print();
    return 0;
}