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
[2024 국민대학교 & 중앙대학교 연합 프로그래밍 경진대회 Open Contest]
32752번 수열이에요?
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, L, R;
	cin >> N >> L >> R;

	vector<int>nums(N);
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		nums[i] = input;
	}

	sort(nums.begin()+L-1,nums.begin()+R);


	int compare = nums[0];
	bool is = true;
	for (int i = 1; i < N; ++i) {
		if (compare > nums[i]) {
			is = false;
			break;
		}
		compare = nums[i];
	}
	if (!is)cout << 0;
	else cout << 1;


}

