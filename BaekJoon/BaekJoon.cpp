#include <iostream>
#include <string>
#include <numeric>
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
================= 2024-12-02================
[그리디] 1931번 회의실 배정

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>>conferences(N);
	for (int i = 0; i < N; ++i) {
		cin >> conferences[i].first >> conferences[i].second;
	}
	sort(conferences.begin(), conferences.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
		});
	int cur_end = -1;
	int cnt{};
	pair<int, int> first_time=conferences[0];
	for (int i = 1; i < N; ++i) {
		if (conferences[i].first >= first_time.second) {
			cnt++;
			first_time = conferences[i];
		}
	}
	cout << cnt;

	
}

