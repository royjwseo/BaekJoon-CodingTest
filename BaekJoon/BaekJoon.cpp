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
4949 균형잡힌 세상
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    
        
    while (true) {
        string input;
        getline(cin, input);

        if (input == ".") break;  // 종료 조건

        stack<char> mystack;
        bool check = true;

        for (char ch : input) {
            if (ch == '(' || ch == '[') {
                mystack.push(ch);
            }
            else if (ch == ')') {
                if (mystack.empty() || mystack.top() != '(') {
                    check = false;
                    break;
                }
                else {
                    mystack.pop();
                }
            }
            else if (ch == ']') {
                if (mystack.empty() || mystack.top() != '[') {
                    check = false;
                    break;
                }
                else {
                    mystack.pop();
                }
            }
        }

        // 최종 결과 출력
        if (check && mystack.empty()) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
}


