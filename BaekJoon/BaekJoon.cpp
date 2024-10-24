#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-24================
- 백준 
2467번 용액

산성 1~10억
알칼리 -1 ~-10억 

*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> liquids(N);
    for (int i = 0; i < N; ++i) {
        cin >> liquids[i];
    }
    
    int left = 0;
    int right = N - 1;

    int sum{};
    int result=INT_MAX;
    int result_left{}, result_right{};
    while (left < right) {
        sum = liquids[left] + liquids[right];
        if (abs(sum) <= result) {
            result = abs(sum);
            result_left = left;
            result_right = right;
        }
        if (sum > 0) {
            right--;
        }
        else if (sum < 0) {
            left++;
        }
        else {
            result_left = left;
            result_right = right;
        }
      
        
    }

    cout << liquids[result_left] << ' ' << liquids[result_right];
}

