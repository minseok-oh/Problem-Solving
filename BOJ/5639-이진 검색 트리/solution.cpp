#include <bits/stdc++.h>
using namespace std;
vector<int> tree;

void input(){
    int temp;
    while(cin >> temp){
        tree.push_back(temp);
    }
}

void search(int start, int finish){
    if(start + 1 == finish){
        cout << tree[start] << "\n";
    }
    else if(start + 1 < finish){
        int here_node = tree[start], mid = finish;
        for(int i = start + 1; i < finish; i++){
            if(here_node < tree[i]){
                mid = i;
                break;
            }
        }

        search(start + 1, mid);
        search(mid, finish);
        cout << tree[start] << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    search(0, tree.size());
    return 0;
}