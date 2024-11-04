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
삽입 정렬 구현
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

    for (int i = 1; i < N; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;

        }
        nums[j + 1] = key;
       
    }
    for (int& a : nums) {
        cout << a << '\n';
    }
}


