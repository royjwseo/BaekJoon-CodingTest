#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-15================
24511 queuestack
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> which(N);
    for (int i = 0; i < N; ++i) {
        cin >> which[i];
    }

    deque<int> q;
    for (int i = 0; i < N; ++i) {  
        int input;
        cin >> input;
        if (which[i] == 0) {
            q.push_front(input);
        }

    }
    vector<int>answer;
    int len;
    cin >> len;
    for (int i = 0; i < len; ++i) {
        int num;
        cin >> num;
        q.push_back(num);
        answer.push_back(q.front());
        q.pop_front();
    }
    for (int& a : answer) {
        cout << a << ' ';
    }
}


