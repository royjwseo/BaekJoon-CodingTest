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
================= 2024-11-08================
2559번 수열

*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int N;
    int K;
    cin >> N >> K;

    vector<int> adds(N + 1);

    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        adds[i] = adds[i - 1] + a;
    }

    int max = INT_MIN;
    int left = 0;
    int right = left + K;
    while (right < adds.size()) {
        
        int sum = adds[right] - adds[left];
        if (sum > max)max = sum;
        left++;
        right++;
    }
    cout << max;

}


