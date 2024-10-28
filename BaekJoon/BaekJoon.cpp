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
================= 2024-10-28================
10989번 수 정렬하기 3
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N;
    cin >> N;
    int a;
    array<int, 10000>nums{};
    for (int i = 0; i < N; ++i) {
        cin >> a;
        nums[a]++;
    }
    for (int i = 1; i < 10000; ++i) {
        if (nums[i] > 0) {
            for (int j = 0; j < nums[i]; j++)
                cout << i << '\n';
        }
    }
}


