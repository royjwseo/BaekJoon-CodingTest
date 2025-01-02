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
================= 2025-01-02================
[Dijikstra] 1238번 파티
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<pair<int, int>>>roads;
vector<int>spent_time;
vector<vector<int>>timelist;

void Dijikstra(int start) {
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	spent_time[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cur_vill = pq.top().second;
		int cur_spent = pq.top().first;

		pq.pop();
		if (cur_spent > spent_time[cur_vill])continue;

		for (auto& next : roads[cur_vill]) {
			int next_vill = next.first;
			int next_spent = next.second;
			if (spent_time[cur_vill] + next_spent < spent_time[next_vill]) {
				spent_time[next_vill] = spent_time[cur_vill] + next_spent;
				pq.push({ spent_time[next_vill],next_vill });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, X, M;
	cin >> N >> M >> X;
	roads.resize(N + 1);
	spent_time.resize(N + 1, numeric_limits<int>::max());
	timelist.resize(N + 1);
	for (int i = 0; i < M; ++i) {
		int from, to, amount;
		cin >> from >> to >> amount;
		roads[from].push_back({ to,amount });
	}

	for (int i = 1; i <= N; ++i) {
		Dijikstra(i);
		timelist[i] = spent_time;
		fill(spent_time.begin(), spent_time.end(), numeric_limits<int>::max());
	}
	
	int max_res{};
	for (int i = 1; i <= N; ++i) {
		int res = timelist[X][i] + timelist[i][X];
		max_res = max(max_res, res);
	}
	cout << max_res;
}

