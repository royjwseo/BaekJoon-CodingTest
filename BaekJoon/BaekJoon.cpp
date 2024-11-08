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
================= 2024-11-08================
1655번 가운데를 말해요
*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    priority_queue<int, vector<int>, greater<int>>min_heap;
    priority_queue<int>max_heap;
   

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;

        if (max_heap.empty() || input < max_heap.top()) {
            max_heap.push(input);
        }
        else {
            min_heap.push(input);
        }

        if (max_heap.size() > min_heap.size()+1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        cout << max_heap.top()<<'\n';
    }
}


