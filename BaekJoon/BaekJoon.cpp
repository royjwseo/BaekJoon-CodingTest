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
[이분 탐색 복습] 1654번 랜선 자르기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int K, N;
	cin >> K >> N;

	vector<long long>lansons(K);
	for (int i = 0; i < K; ++i) {
		cin >> lansons[i];
	}

	sort(lansons.begin(), lansons.end());

	long long left = 1;
	long long right = lansons[lansons.size()-1];
	long long cur_result{};
	while (left <= right) {
		long long cnt{};
		
		long long mid = left + (right - left) / 2;
		for (auto a : lansons) {
			cnt += a / mid;
		}
		if (cnt >= N) {
			left = mid + 1;
			cur_result = mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << cur_result;
}

