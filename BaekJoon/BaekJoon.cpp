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
10799 쇠막대기
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    string sen;
    cin >> sen;

    stack<char> sticks;
    int cnt{};
    for (char a : sen) {
        if (a == '(')sticks.push(a);
        else if (a == ')' && !sticks.empty()) {
            sticks.pop();
            cnt += sticks.size();
        }

    }
    cout << cnt;
}


