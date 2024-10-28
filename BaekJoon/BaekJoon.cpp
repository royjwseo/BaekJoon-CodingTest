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
2587번 대표값2
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    
    vector<float> nums(5);
    float sum{};
    for (int i = 0; i < 5; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }
    sort(nums.begin(), nums.end());
   
    cout << sum / 5.f << '\n' << nums[2];
}


