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
================= 2025-01-20================
[이분 탐색(실패)] 12015번 가장 긴 증가하는 부분 수열 2 
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int>nums(N);
	for (int i = 0; i < N; ++i)cin >> nums[i];
	vector<int>ans;
	for (int i = 0; i < N; ++i) {
		vector<int>::iterator iter = lower_bound(ans.begin(), ans.end(), nums[i]);
		if (iter == ans.end()) {
			ans.push_back(nums[i]);
		}
		else {
			*iter = nums[i];
		}
	}
	cout << ans.size();
}

