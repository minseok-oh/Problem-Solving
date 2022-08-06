#include <bits/stdc++.h>
using namespace std;
int board[9][9];
vector<pair<int, int>> empty_spot;

void input(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                empty_spot.push_back(make_pair(i, j));
            }
        }
    }
}

bool check_number(int here, int value){
    int here_y = empty_spot[here].first;
    int here_x = empty_spot[here].second;

    for(int i = 0; i < 9; i++){
        if(board[here_y][i] == value) return false;
        if(board[i][here_x] == value) return false;
    }

    int y = here_y / 3, x = here_x / 3;
    for(int i = y * 3; i < (y + 1) * 3; i++){
        for(int j = x * 3; j < (x + 1) * 3; j++){
            if(board[i][j] == value) return false;
        }
    }
    return true;
}

bool flag = false;
void sudoku(int here){
    if(flag) return ;
    if(here == empty_spot.size()){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        flag = true;
        return ;
    }

    for(int i = 1; i <= 9; i++){
        pair<int, int> here_value = empty_spot[here];
        if(check_number(here, i)){
            board[here_value.first][here_value.second] = i;
            sudoku(here + 1);
            board[here_value.first][here_value.second] = 0;
        }
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    sudoku(0);
    return 0;
}