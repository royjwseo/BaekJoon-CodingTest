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
24511번 queuestack
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int>make(N);
    for (int i = 0; i < N; ++i) {
        cin >> make[i];
    }
    vector<vector<int>>stackqueue(N, vector<int>(2));

    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
            stackqueue[i][0] = input;    
    }
    int M;
    cin >> M;
    vector<int>answer;
    for (int i = 0; i < M; ++i) {
        int input;
        cin >> input;
        stackqueue[0][1] = input;
        int num=input;
        for (int i = 0; i < N; ++i) {         
            stackqueue[i][1] = num;
            if (make[i] == 0) {// 큐 앞에서 뺌             
                num = stackqueue[i][0];
                stackqueue[i][0] = stackqueue[i][1];            
            }
            else if(make[i]==1) {//스택 뒤에서 뺌
                num = stackqueue[i][1];
            }
            if (i == N - 1) {
                answer.push_back(num);
            }
        }
    }

    for (int a : answer) {
        cout << a << ' ';
    }
}


