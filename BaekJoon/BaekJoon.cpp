#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-20================
1167 트리의 지름

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<pair<int, int>>> nodes;
vector<bool> visited;
vector<int> dist;

void BFS(int here) {

	visited[here] = true;
	queue<int>q;
	q.push(here);
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		int size = nodes[front].size();
		for (int i = 0; i < size; ++i) {
			pair<int,int> other = nodes[front][i];
			if (!visited[other.first]) {
				visited[other.first] = true;
				dist[other.first] = dist[front] + other.second;
				q.push(other.first);
			}
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int V;
	cin >> V;

	nodes.resize(V+1);
	visited.resize(V + 1);
	dist.resize(V + 1);

	for (int i = 1; i <= V; ++i) {
		int input;
		cin >> input;
		int first{};
		while (1) {
			cin >> first;
			if (first == -1)break;
			int second;
			cin >> second;
			nodes[input].push_back({ first,second });
		}
	}


	BFS(1);
	int max = -1;
	int next{};
	for (int i = 1; i <= V; ++i) {
		if (dist[i] > max) {
			max = dist[i];
			next = i;
		}
	}

	visited.assign(V + 1, false);
	dist.assign(V + 1, 0);
	BFS(next);
	int answer{};
	for (int i = 1; i <= V; ++i) {
		if (dist[i] > answer) {
			answer = dist[i];
		}
	}
	cout << answer;
}


