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
[이진 탐색] 2110번 공유기 설치

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	using ll = long long;
	int N,C;
	cin >> N >> C;

	vector<ll>vec(N);
	for (int i = 0; i < N; ++i)cin >> vec[i];

	sort(vec.begin(), vec.end());

	ll min =1;
	ll max = vec[N - 1]-vec[0];
	int result{};
	while (min <= max) {
		ll mid = (min + max) / 2;
		ll last_pos = vec[0];
		int cnt=1;
		for (int i = 1; i < N; ++i) {
			if (vec[i] - last_pos >= mid) {
				cnt++;
				last_pos = vec[i];
			}
		}
		if (cnt >= C) {
			result = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}

	}
	cout << result;
}

