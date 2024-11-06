#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-06================
11286 절댓값 힙

*/

struct abs_compare {

    bool operator()(int a, int b) {
        if (abs(a) == abs(b))return a>b;
        else
        return abs(a) > abs(b);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
  
    int N;
    cin >> N;

    priority_queue<int, vector<int>, abs_compare>pq;

    for (int i = 0; i < N; ++i) {
        int input{};
        cin >> input;
        if (input == 0) {
            if (pq.empty()) {
                cout << "0\n";
            }else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(input);
        }
    }
 
}


