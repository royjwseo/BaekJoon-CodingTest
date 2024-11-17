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
================= 2024-11-17================
24480번 알고리즘 수업 - 깊이 우선 탐색 2

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/
vector<vector<int>>adjacent;
vector<int> visited;
int n{};

void BFS(int here) {
	
	if (visited[here]==0) {
		visited[here] = ++n;
	}
	int n = adjacent[here].size();
	for (int i = 0; i < n; ++i) {
		
		if (visited[adjacent[here][i]]==0)
			BFS(adjacent[here][i]);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int M;
	cin >> N >> M;
	int R;
	cin >> R;

	adjacent.resize(N+1);
	visited.resize(N+1, 0);
	
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adjacent[a].push_back(b);
		adjacent[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) {
		sort(adjacent[i].begin(), adjacent[i].end(),greater<int>());
	}
	BFS(R);
	for (int i = 1; i <= N; ++i) {
		cout << visited[i] << '\n';
	}


	

}


