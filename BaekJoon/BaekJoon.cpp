#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
================= 2024-11-04================
2750번 수 정렬하기1

버블 정렬 구현
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N;
    cin >> N;
    //입력은 1000 이므로 log(n^2)여도 1'000'000 이므로 버블로 해도됨.

    vector<int>nums(N);
    for (int i = 0; i < N; ++i)cin >> nums[i];

    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j < N-i-1; j++) {
            if (nums[j] > nums[j+1])swap(nums[j], nums[j+1]);
        }
    }

    for (int& a : nums) {
        cout << a << '\n';
    }

}


