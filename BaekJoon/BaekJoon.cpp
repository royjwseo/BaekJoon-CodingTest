#include <iostream>
#include <string>
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
================= 2024-12-14================
[코테 강의 1주차 문자열,누적합,구현] 2559 수열
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int>added_nums(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		int input;
		cin >> input;
		added_nums[i] = added_nums[i - 1] + input;
	}

	int max = numeric_limits<int>::min();
	int left = 0;
	while (left+K <= N) {
		int sum = added_nums[left+K] - added_nums[left];
		if (sum > max)max = sum;
		left++;
	}

	cout << max;

}

