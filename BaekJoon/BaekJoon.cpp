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
2018번 수들의합 5


*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int left = 1;
    int right = 1;

    int sum=1;
    int cnt{};
    while (right <= N) {
            
        if (sum > N) {
            sum -= left;
            left++;     
        }
        else if (sum < N) {
            right++;
            sum += right;
        }
        else {
            cnt++;       
            right++;
            sum += right;
            sum -= left;
            left++;
        }
    }
    cout << cnt;


}


