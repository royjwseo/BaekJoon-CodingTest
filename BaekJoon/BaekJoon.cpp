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
28279번 덱 2

//
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    deque<int> dq;
    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        switch (input) {
        case 1:
            int num;
            cin >> num;
            dq.push_front(num);
            break;
        case 2:
            int num2;
            cin >> num2;
            dq.push_back(num2);
            break;
        case 3:
            if (!dq.empty()) {
                cout << dq.front()<<'\n';
                dq.pop_front();
            }
            else {
                cout << "-1\n";
            }
            break;
        case 4:
            if (!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else {
                cout << "-1\n";
            }
            break; 
        case 5:
            cout << dq.size()<<'\n';
            break; 
        case 6:
            (dq.empty()) ? cout << "1\n" :cout<<"0\n";
            break; 
        case 7:
            (dq.empty()) ? cout << "-1\n" : cout << dq.front() << '\n';
            break;
        case 8:
            (dq.empty()) ? cout << "-1\n" : cout << dq.back() << '\n';
            break;
        }
    }
    
}


