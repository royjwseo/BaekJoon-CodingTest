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
10773번 제로

*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int K;
    cin >> K;
    vector<int> moneystack;
    for (int i = 0; i < K; ++i) {
        int money;
        cin >> money;
        if (money == 0) {
            moneystack.pop_back();
        }
        else {
            moneystack.push_back(money);
        }
    }

    int sum{};
    for (int& a : moneystack) {
        sum += a;
    }
    cout << sum;
 
   
}


