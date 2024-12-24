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
================= 2024-12-24================
[6주차 이분탐색 & LIS(최대증가부분수열)] 6236번 용돈 관리
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int>money(N);
	int sum{};
	int max_money{};
	for (int i = 0; i < N; ++i) {
		cin >> money[i];
		sum += money[i];
		max_money = max(max_money, money[i]);
	}
	int left = max_money;
	int right = sum;
	int result{};
	while (left <= right) {
		int mid = (left + right) / 2;

		int leftover = mid;
		int cnt{};
	
		for (int i = 0; i < N; ++i) {
			if (leftover - money[i] < 0) {
				cnt++;
				leftover = mid - money[i];
			}
			else {
				leftover -= money[i];
			}
		}
		if (leftover > 0)cnt++;

		if (cnt > M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			result = mid;
		}

	}
	cout << result;

}

