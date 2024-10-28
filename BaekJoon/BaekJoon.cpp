#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

/*
================= 2024-10-28================
28278 스택 수열

*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N;
    cin >> N;
    stack<int> answer;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        switch (a) {
        case 1:
            int input;
            cin >> input;
            answer.push(input);
            break;
        case 2:
            if (!answer.empty()) {
                cout << answer.top() << '\n';
                answer.pop();
            }
            else {
                cout << "-1\n";
            }
          
            break;
        case 3:
            cout << answer.size() << '\n';
            break;
        case 4:
            cout << (answer.empty() ? "1\n" : "0\n");
            break;
        case 5:
            if (!answer.empty()) {
                cout << answer.top() << '\n';
            }
            else {
                cout << "-1\n";
            }
            break;
        }
    }
    
}


