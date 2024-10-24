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
1806번 부분합
*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int S;
    cin >> S;

    vector<long long> nums(N+1);
    for (int i = 1; i <=N; ++i) {
        int a;
        cin >> a;
        nums[i] = nums[i - 1] + a;
    }
    int left = 0;
    int right = 1;

    long long sum{};
    int result_len=INT_MAX;
    while (right <= N) {
        sum = nums[right] - nums[left];
  
        if (sum >= S) {
            if (right - left < result_len) {
                result_len = right - left;
            }
            left++;
        }
        else {
            right++;
        }
        
        
    }
    if (result_len == INT_MAX)result_len = 0;
    cout << result_len;

}

