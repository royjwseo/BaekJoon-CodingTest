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
================= 2024-12-03================
12738번 가장 긴 증가하는 부분 수열 3

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>adjacents;
vector<pair<int,int>> visited;

void BFS(int start,int cnt) {

	queue<int> q;
	q.push(start);
	visited[start].first = true;

	
	while (!q.empty()) {
		int front = q.front();
		int size = adjacents[front].size();
		q.pop();
		for (int i = 0; i < size; ++i) {
			int next = adjacents[front][i];
			if (!visited[next].first) {
				visited[next].first = true;
				visited[next].second = visited[front].second+1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n_cities;
	cin >> n_cities;
	int n_roads;
	cin >> n_roads;

	int len;
	cin >> len;
	int start;
	cin >> start;

	adjacents.resize(n_cities+1);
	visited.resize(n_cities+1,{false,0});
	for (int i = 0; i < n_roads; ++i) {
		int a, b;
		cin >> a >> b;
		adjacents[a].push_back(b);
	}
	int cnt{};
	BFS(start,cnt);

	bool has = false;
	for (int i = 1; i <= n_cities; ++i) {
		if (visited[i].second == len) {
			cout << i<<'\n';
			has = true;
		}
	}
	if (!has) {
		cout << -1;
	}
}

