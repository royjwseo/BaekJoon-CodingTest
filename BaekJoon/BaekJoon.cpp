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
================= 2024-11-14================
11866번 요세푸스 문제0
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int>answer;

    int K;
    cin >> K;

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    while (1) {
        if (q.empty())break;
        int cnt = K-1;
        while (cnt > 0) {
            int front = q.front();
            q.pop();
            q.push(front);
            cnt--;
        }
        int front = q.front();
        answer.push_back(front);
        q.pop();

    }
   
    cout << '<';
    for (vector<int>::iterator iter = answer.begin(); iter != answer.end(); ++iter) {
        if (iter == answer.end() - 1) {
            cout << *iter;
        }
        else {
            cout << *iter << ", ";
        }
    }
    
    cout << ">\n";

}


