#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

/*
================= 2024-10-25================
10828번 스택

*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   

    int N;
    cin >> N;

    string input;
    stack<int> my_stack;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        if (input == "push") {
            int a;
            cin >> a;
            my_stack.push(a);
        }
        else if (input == "top") {
            if (my_stack.empty()) {
                cout << "-1\n";
            }
            else {
                cout << my_stack.top() << '\n';
            }
            
        }
        else if (input == "size") {
            cout << my_stack.size()<<'\n';
        }
        else if (input == "pop") {
            if (my_stack.empty()) {
                cout << "-1\n";
            }
            else {
                cout << my_stack.top() << '\n';
                my_stack.pop();
            }
        }
        else if (input == "empty") {
            (my_stack.empty()) ? cout << "1\n" : cout << "0\n";
        }
    }
   
 
   
}


