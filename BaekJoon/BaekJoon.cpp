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
[5주차 그리디,라인스위핑,투포인터] 2109번 순회강연
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
		cin >> conf[i].first >> conf[i].second;
	}
	sort(conf.begin(), conf.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
		if (l.second == r.second)return l.first > r.first;
		return l.second < r.second;
		});

	priority_queue<int,vector<int>, greater<int>>pq;

	for (auto& con : conf) {
		pq.push(con.first);
		if (pq.size() > con.second) {
			pq.pop();
		}
	}

	int sum{};

	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;

	
}

