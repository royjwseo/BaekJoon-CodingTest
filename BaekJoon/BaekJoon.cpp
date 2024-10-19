#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-19 ================
- 백준 
3273번 두수의합

N 개의
각 수 1과 백만 사이
  



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
	int X;
	cin >> X;

	sort(nums.begin(), nums.end());

	int left = 0;
	int right = N - 1;
	int cnt{};

	
		left = 0;
		right = N - 1;
		while (left < right) {
			if (nums[left] + nums[right] > X) {

				right--;
			}
			else if (nums[left] + nums[right] < X) {
				left++;
			}
			else {
				cnt++;
				left++;
				right--;
			}
		}
	
	cout << cnt;


}


