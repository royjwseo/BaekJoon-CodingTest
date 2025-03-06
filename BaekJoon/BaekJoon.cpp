#include <iostream>
#include <string>
#include <tuple>
#include <numeric>
#include <sstream>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

/*
================= 2025-03-06================
11053번 가장 긴 증가하는 부분 수열
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
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

	vector<int>dp(N, 1);
	int last_index = 0;
	for (int i = 1; i < N; ++i) {

		for (int j = i; j >= 0; --j) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[j] + 1,dp[i]);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}


