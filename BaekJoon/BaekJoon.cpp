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
[5주차 그리디,라인스위핑,투포인터] 14469 소가 길을 건너간 이유3
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>>cows(N);
	for (int i = 0; i < N; ++i) {
		cin >> cows[i].first >> cows[i].second;
	}
	sort(cows.begin(), cows.end());

	int cur_time=cows[0].first;
	queue<pair<int,int>> q;
	for (auto& cow : cows) {
		q.push(cow);
		if (!q.empty()) {
			auto cur_cow=q.front();
			if (cur_cow.first >= cur_time) {
				cur_time = cur_cow.first + cur_cow.second;
			}
			else {
				cur_time += cur_cow.second;
			}
			q.pop();
		}
	}
	cout << cur_time;
}

