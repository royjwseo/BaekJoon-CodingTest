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
2018번 세 용액


*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long>liquids(N);
    for (int i = 0; i < N; ++i) {
        cin >> liquids[i];
    }
    sort(liquids.begin(),liquids.end());

    int left = 0;
    int middle = 1;
    int right = N - 1;
    long long sum{};
    long long max = LONG_MAX;


    int result_left{}, result_right{}, result_middle{};
    while (left < N-2) {
        middle = left + 1;
        right =  N-1;
     
        while (middle < right) {
            sum = liquids[left] + liquids[right] + liquids[middle];

            if (abs(sum) < max) {
                max = abs(sum);
                result_left = left;
                result_middle = middle;
                result_right = right;
            }
            if (sum > 0) {
                right--;
            }
            else if (sum < 0) {
                middle++;
            }
            else {
                break;
            }
        }
        left++;

    }
    cout << liquids[result_left] << ' ' << liquids[result_middle] << ' ' << liquids[result_right];

   
}


