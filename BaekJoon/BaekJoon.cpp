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
12789 도키도키 간식드리미
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N;
    cin >> N;

    int a;
    int person = 1;
    stack<int> snack_line;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        if (a == person) {
            person++;
        }
        else {
            snack_line.push(a);
        }
        while (!snack_line.empty() && snack_line.top() == person) {
            snack_line.pop();
            person++;
        }
    }
    if (snack_line.empty()) {
        cout << "Nice";
    }
    else {
        cout << "Sad";
    }
}


