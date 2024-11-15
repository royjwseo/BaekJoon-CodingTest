#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-15================
1920번 수 찾기

//
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

bool binary_search(int n, vector<int>& nums) {
    int right = nums.size()-1;
    int left = 0;
    int index; 
    while (left<=right) {
        index = (right + left) / 2;
        if (n > nums[index]) {
            left = index + 1;
        }
        else if (n < nums[index]) {
            right = index-1;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        nums.push_back(input);
    }
    sort(nums.begin(), nums.end()); //O(nlogn) 100000*16.61 =160만
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int input;
        cin >> input;
        if (binary_search(input, nums)) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    
}


