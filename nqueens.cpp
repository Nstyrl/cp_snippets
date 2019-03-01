#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;

int n;

struct Point {
    int x; int y;
};

vector <Point> queens;
long long answer = 0;

bool check(Point p) {
    for(int i = 0; i < queens.size(); i++) {
        if(queens[i].x == p.x || queens[i].y == p.y ||
           abs(queens[i].x - p.x) == abs(queens[i].y - p.y)) {
            return false;
        }
    }
    return true;
}

void backtracking(int queenLeft) {
    if(queenLeft == 0) {
        answer++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(check(Point({queenLeft, i}))) {
            queens.push_back(Point({queenLeft, i}));
            backtracking(queenLeft - 1);
            queens.pop_back();
        }
    }
}


int main() {
    cin >> n;
    backtracking(n);
    cout << answer << endl;
}
