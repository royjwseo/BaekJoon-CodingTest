#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-25================
9012번 괄호


*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N;
    cin >> N;


    for (int i = 0; i < N; ++i) {
        string sen;

        int cnt{};
       bool start = false;
        cin >> sen;
        for (char a : sen) {
            if (a == '(') {
                start = true;
                cnt++;
            }
            else if (a == ')')
            {
                cnt--;
                if (cnt < 0)break;
                if (cnt == 0)start = false;
            }
       }
        if (cnt == 0 && !start) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
   
   
}


