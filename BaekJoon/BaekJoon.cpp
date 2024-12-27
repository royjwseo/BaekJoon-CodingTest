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
[5주차 그리디,라인스위핑,투포인터] 1781번 컵라면
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>>deadlines(N+1);
	for (int i = 1; i <= N; ++i) {
		cin >> deadlines[i].first >> deadlines[i].second;
	}

	priority_queue<int, vector<int>, greater<int>>pq;

	sort(deadlines.begin(), deadlines.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
		if (l.first == r.first)return l.second > r.second;
		return l.first < r.first;
		});

	for (int i = 1; i <= N; ++i) {
		pq.push(deadlines[i].second);
		if (pq.size() > deadlines[i].first) {
			pq.pop();
		}
	}
	int result{};
	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	cout << result;
	
}

