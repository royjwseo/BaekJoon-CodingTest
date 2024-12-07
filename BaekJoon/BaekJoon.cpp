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
[이진 탐색] 2805번 나무 자르기

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	

	int N;
	int M;
	cin >> N >> M;

	vector<long long> trees(N);
	for (int i = 0; i < N; ++i)cin >> trees[i];

	sort(trees.begin(), trees.end());
	long long min = 0;
	long long max = trees[N - 1];

	long long result{};
	while (min < max) {
		long long mid = (min + max) / 2;
		long long sum{};
		for (long long a : trees) {
			if (a  > mid) {
				sum += (a - mid);
			}
		}
		if (sum >= M) {
			min = mid+1;
			result = mid;
		}
		else if (sum < M) {
			max = mid-1;
		}
		
	}
	cout << result;
}

