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
[이분 탐색 복습] 2805번 나무 자르기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

bool leftover(const vector<long long>& trees, long long val, long long get) {
	long long leftover{};
	for (auto a : trees) {
		if (a - val >= 0)
			leftover += a - val;
	}
	if (leftover >= get)return true;
	else return false;
}

long long binary(const vector<long long>& trees, long long get) {
	long long left = 0;
	long long right = trees[trees.size() - 1];
	
	long long result{};
	while (left <= right) {
		long long mid= left + (right - left) / 2;

		if (leftover(trees, mid, get)) {
			left = mid + 1;
			result = mid;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<long long>trees(N);
	for (int i = 0; i < N; ++i) {
		cin >> trees[i];
	}
	sort(trees.begin(), trees.end());

	cout << binary(trees, M);
	
}

