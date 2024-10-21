#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-21================
- 백준 
2798번 블랙잭
시간 제한 1초
입력 최대 100개 중 3개 뽑는 100 x 99 x 98 /6 -> 161700
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int>nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	int sum{};
	int min = INT_MAX;
	for (int i = 0; i < N - 2; ++i) {
		for (int j = i+1; j < N - 1; ++j) {
			sum = nums[i] + nums[j];
			for (int k = j + 1; k < N; ++k) {
				if (nums[k] > M - sum) {
					continue;
				}
				else {
					if (M - sum - nums[k] <= min)min = M - sum - nums[k];
				}
			}
		}
	}
	cout << M - min;


}


