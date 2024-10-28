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
1874 스택 수열

*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<char> result;
    stack<int> mystack;

    int a = 1;
    bool check = true;
    for (int i = 0; i < n; ++i) {
        int target = nums[i];
        
        if (a <= target) {
            while (a <= target) {
                mystack.push(a++);
                result.push_back('+');
            }
        }
       
            if (target == mystack.top()) {
                mystack.pop();
                result.push_back('-');
            }
            else {
                cout << "NO";
                check = false;
                break;
            }
        


    }
    if (check) {
        for (char a : result) {
            cout << a << '\n';
        }
    }
    
}


