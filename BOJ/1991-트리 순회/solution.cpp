#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    int left, right;
};
vector<node> tree;

void input(){
    cin >> n;
    tree.resize(n);

    char cur_node, left_node, right_node;
    for(int i = 0; i < n; i++){
        cin >> cur_node >> left_node >> right_node;
        tree[cur_node - 'A'] = {left_node - 'A', right_node - 'A'};
    }
}

void preorder(int here){
    cout << (char)(here + 'A');
    if(tree[here].left + 'A' != '.') preorder(tree[here].left);
    if(tree[here].right + 'A' != '.') preorder(tree[here].right);
}

void inorder(int here){
    if(tree[here].left + 'A' != '.') inorder(tree[here].left);
    cout << (char)(here + 'A');
    if(tree[here].right + 'A' != '.') inorder(tree[here].right);
}

void postorder(int here){
    if(tree[here].left + 'A' != '.') postorder(tree[here].left);
    if(tree[here].right + 'A' != '.') postorder(tree[here].right);
    cout << (char)(here + 'A');
}

void solve(){
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}