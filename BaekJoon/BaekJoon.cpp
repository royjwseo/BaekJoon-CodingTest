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
9012번 괄호

stack 활용

*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
   

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string sen;
        cin >> sen;

        stack<char> _container;
        bool isValid = true;

        for (char a : sen) {
            if (a == '(') {
                _container.push(a);
            }
            else if (a == ')') {
                if (_container.empty()) {
                    isValid = false;
                    break;
                }
                else {
                    _container.pop();
                }
            }
        }

        if (isValid && _container.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
   
 
   
}


