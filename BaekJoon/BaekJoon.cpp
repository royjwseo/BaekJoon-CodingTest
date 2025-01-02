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
[Dijikstra] 1753번 최단경로
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


vector<vector<pair<int, int>>>adjacents;
vector<int>dist;

void Dijikstra(int start) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curWeight = pq.top().first;
		pq.pop();
		if (dist[curNode] < curWeight)continue;

		for (pair<int, int>& next : adjacents[curNode]) {
			int nextNode = next.first;
			int nextWeight = next.second;

			if (dist[curNode] + nextWeight < dist[nextNode]) {
				dist[nextNode] = dist[curNode] + nextWeight;
				pq.push({ dist[nextNode],nextNode });
			}

		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int V, E, K;
	cin >> V >> E >> K;
	adjacents.resize(V + 1);
	dist.resize(V + 1,numeric_limits<int>::max());

	for (int i = 1; i <= E; ++i) {
		int from;
		cin >> from;
		int to, weight;
		cin >> to >> weight;
		adjacents[from].push_back({ to,weight });
	}

	Dijikstra(K);

	for (int i = 1; i <= V; ++i) {
		if (dist[i] == numeric_limits<int>::max()) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}

}

