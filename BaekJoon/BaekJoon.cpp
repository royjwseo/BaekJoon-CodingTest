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
================= 2025-01-03================
[Dijikstra] 1504번 특정한 최단 경로
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


vector<vector<pair<int, int>>>adjacents;
vector<int>parent;

vector<int> Dijikstra(int start,int num) {

	vector<int> dist(num + 1, numeric_limits<int>::max());
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,start });
	parent[start] = start;

	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();
		if (curCost > dist[curNode])continue;

		for (auto& next : adjacents[curNode]) {
			int nextNode = next.first;
			int nextCost = next.second;
			if (dist[curNode] + nextCost < dist[nextNode]) {
				dist[nextNode] = dist[curNode] + nextCost;
				parent[nextNode] = curNode;
				pq.push({ dist[nextNode],nextNode });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, E;
	cin >> N >> E;

	adjacents.resize(N+1);
	parent.resize(N + 1);

	for (int i = 0; i < E; ++i) {
		int from, to, weight;
		cin >> from >> to >> weight;
		adjacents[from].push_back({ to,weight });
		adjacents[to].push_back({ from,weight });
	}
	
	int pass_from, pass_to;
	cin >> pass_from >> pass_to;

	vector<int> FullDist=Dijikstra(1,N);
	vector<int> v1v2 = Dijikstra(pass_from, N);
	vector<int> v2v1 = Dijikstra(pass_to, N);

	long long v1v2Dist = FullDist[pass_from] + v1v2[pass_to] + v2v1[N];
	long long v2v1Dist = FullDist[pass_to] + v2v1[pass_from] + v1v2[N];

	long long minDist = min(v1v2Dist, v2v1Dist);

	if (minDist >= numeric_limits<int>::max()) {
		cout << -1;
	}
	else {
		cout << minDist;
	}


}

