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
1927번 최소 힙

*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
  
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>>pq;

    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        if (input == 0) {
            if (pq.empty())cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(input);
        }
    }
 
}


