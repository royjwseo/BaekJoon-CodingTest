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
================= 2025-01-10================
11779번 최소비용 구하기 2
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int N, M;
vector<vector<pair<int, int>>>adjacents;
vector<int>dist;
vector<int>before_stop;

void Dijikstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curDist = pq.top().first;

		pq.pop();
		if (curDist > dist[curNode])continue;

		for (int i = 0; i < adjacents[curNode].size(); ++i) {
			int nextNode = adjacents[curNode][i].first;
			int nextDist = adjacents[curNode][i].second;
			if (curDist + nextDist < dist[nextNode]) {
				dist[nextNode] = curDist + nextDist;
				before_stop[nextNode] = curNode;
				pq.push({ dist[nextNode],nextNode });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	adjacents.resize(N + 1);
	dist.resize(N + 1, numeric_limits<int>::max());
	before_stop.resize(N + 1, 0);

	for (int i = 0; i < M; ++i) {
		int from, to, fee;
		cin >> from >> to >> fee;
		adjacents[from].push_back({ to,fee });
	}

	int ans_from, ans_to;
	cin >> ans_from >> ans_to;

	Dijikstra(ans_from);

	int cur = ans_to;
	int cnt = 1;
	deque<int>ans;
	ans.push_front(cur);
	while (1) {
		int before = before_stop[cur];
		ans.push_front(before);
		cur = before;
		if (before == ans_from)break;
	}

	cout << dist[ans_to] << '\n';
	cout << ans.size() << '\n';
	for (int a : ans)cout << a << ' ';
}

