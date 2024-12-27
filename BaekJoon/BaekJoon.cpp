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
================= 2024-12-27================
[5주차 그리디,라인스위핑,투포인터] 1931번 회의실 배정
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>>conf(N);
	for (int i = 0; i < N; ++i) {
		cin >> conf[i].second >> conf[i].first;
	}

	sort(conf.begin(), conf.end());

	int cnt{};
	pair<int, int>cur={0,0};
	for (auto a : conf) {
		if (a.second >= cur.first) {
			cnt++;
			cur = a;
		}
	}
	cout << cnt;

}

