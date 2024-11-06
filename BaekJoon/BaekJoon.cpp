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
1715 카드 정렬하기

*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int N;
    cin >> N;

    priority_queue<int, vector<int>, std::greater<int>>pq;
    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        pq.push(input);
    }

    int sum{};
    int imsi_sum{};
    int left, right;


    for (int i = 0; i < N - 1; ++i) {
        imsi_sum = 0;
        left = 0; right = 0;
        left = pq.top();
        pq.pop();
        if (!pq.empty()) {
            right = pq.top();
            pq.pop();
        }
        imsi_sum = left + right;
        pq.push(imsi_sum);
        sum += left + right;
    }

  
    cout << sum;
 
}


