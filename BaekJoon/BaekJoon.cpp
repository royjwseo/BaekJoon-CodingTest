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
14938번 서강그라운드
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int N, M, R;
vector<int>items;
vector<vector<pair<int, int>>>adjacents;
vector<int>dist;

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
			int nextCost = adjacents[curNode][i].second;

			if (curDist + nextCost < dist[nextNode]) {
				dist[nextNode] = curDist + nextCost;
				pq.push({ dist[nextNode],nextNode });
			}
		}
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	cin >> N >> M >> R;

	items.assign(N + 1, 0);
	adjacents.resize(N + 1);
	dist.resize(N + 1,numeric_limits<int>::max());


	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		items[i + 1] = input;
	}

	for (int i = 0; i < R; ++i) {
		int from, to, fee;
		cin >> from >> to >> fee;
		adjacents[from].push_back({ to,fee });
		adjacents[to].push_back({ from,fee });
	}

	int ans = -1;

	for (int i = 2; i <= N; ++i) {
		int cnt{};
		fill(dist.begin(), dist.end(), numeric_limits<int>::max());
		Dijikstra(i);
		for (int k = 1; k <= N; ++k) {
			if (dist[k] <= M)cnt += items[k];
		}
		ans=max(ans, cnt);
	
	}

	cout << ans;

}

