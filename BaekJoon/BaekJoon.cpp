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
[Dijikstra] 1916번 최소비용 구하기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


vector<vector<pair<int, int>>>busline;
vector<int>dist;

void Dijikstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curFee = pq.top().first;
		pq.pop();

		if (curFee > dist[curNode])continue;

		for (auto& next : busline[curNode]) {
			int nextNode = next.first;
			int nextFee = next.second;

			if (dist[curNode] + nextFee < dist[nextNode]) {
				dist[nextNode] = dist[curNode] + nextFee;
				pq.push({ dist[nextNode],nextNode });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	busline.resize(N + 1);
	dist.resize(N + 1,numeric_limits<int>::max());

	for (int i = 0; i < M; ++i) {
		int from;
		cin >> from;
		int to, amount;
		cin >> to >> amount;
		busline[from].push_back({ to,amount });
	}

	int ans_from, ans_to;
	cin >> ans_from >> ans_to;
	Dijikstra(ans_from);
	
	cout << dist[ans_to];

}

