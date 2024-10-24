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
1940번
주몽


*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int M;
    cin >> N >> M;
    vector<int>nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = N-1;

    int sum{};
    int result{};
    while (left < right) {
        sum = nums[left] + nums[right];
        if (sum > M) {
            right--;
        }
        else if(sum<M) {
            left++;
        }
        else {
        result++;
        left++;
        right--;
       }
    }
    cout << result;
}
//1 2 3 4 5 7 

