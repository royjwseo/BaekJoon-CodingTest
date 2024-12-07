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
================= 2024-12-07================
[이진 탐색] 1654번 랜선 자르기

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int K, N;
	cin >> K >> N;
	vector<int> lansons(K);
	for (int i = 0; i < K; ++i)cin >> lansons[i];

	sort(lansons.begin(), lansons.end());

	long long min = 0;
	long long max = lansons[K - 1];
	int result{};
	while (min <= max) {
		long long mid = (min + max) / 2;
		long long sum{};

		for (int a : lansons) {
			if (a > mid) {
				sum += a / mid;
			}
		}
		if (sum >= N) {
			result = mid;
			min = mid+1;
		}
		else {
			max = mid - 1;
		}
	}

	cout << result;
}

