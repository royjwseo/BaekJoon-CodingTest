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
================= 2025-02-04================
[이분 탐색 복습] 2110번 공유기 설치
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int C;
	cin >> C;

	vector<long long>houses(N);
	for (int i = 0; i < N; ++i) {
		cin >> houses[i];
	}
	sort(houses.begin(), houses.end());
	long long left = 1;
	long long right = houses[N - 1]-houses[0];
	long long answer{};
	while (left <= right) {
		long long mid = left + (right - left) / 2;
		long long result = 1;
		long long start = houses[0];
		for (int i = 1; i < N; ++i) {
			if (houses[i] - start >= mid) {
				result++;
				start = houses[i];
			}
		}
		if (result >= C) {
			answer = result;
			left = mid + 1;
		}
		else {
			right = mid -1;
		}
	}
	cout << answer;
}

