#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int number;
    int mul_grade, sum_grade;
}Node;

int n;
vector<Node> v;

void input() {
    cin >> n;

    int num, x, y, z;
    for(int i = 0; i < n; i++) {
        cin >> num >> x >> y >> z;
        v.push_back({num, x * y * z, x + y + z});
    }
}

bool comp(const Node& n1, const Node& n2) {
    if (n1.mul_grade == n2.mul_grade) {
        if (n1.sum_grade == n2.sum_grade) {
            return n1.number < n2.number;
        }
        else {
            return n1.sum_grade < n2.sum_grade;
        }
    }
    else {
        return n1.mul_grade < n2.mul_grade;
    }
}

void solve() {
    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < 3; i++) {
        cout << v[i].number << " ";
    }
    cout << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}