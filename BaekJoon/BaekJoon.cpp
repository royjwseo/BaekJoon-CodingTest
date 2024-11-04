#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-04================
2750번 수 정렬하기

선택 정렬 구현하기
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int N;
    cin >> N;

    vector<int>nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    for (int i = 0; i < N; ++i) {
        vector<int>::iterator p = min_element(nums.begin()+i, nums.end());
        if(p!=nums.begin()+i)
        swap(*(nums.begin()+i), *p);
    }
    for (int& p : nums) {
        cout << p << '\n';
    }

}


