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
24445번 알고리즘 수업 - 너비 우선 탐색 2

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>> adjacent;
vector<int> visit;
int n = 1;

void BFS(int here) {

	queue<int> q;
	q.push(here);
	visit[here] = n++;
	while (!q.empty()) {
		int front = q.front();
		
		q.pop();

		int a = adjacent[front].size();
		for (int i = 0; i < a; ++i) {
			if (visit[adjacent[front][i]]==0) {
				visit[adjacent[front][i]] = n++;
				q.push(adjacent[front][i]);
			}
		}

	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int M;
	int R;
	cin >> N >> M >> R;
	
	adjacent.resize(N+1);
	visit.resize(N + 1, 0);
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
		cout << visit[i]<<'\n';
	}

	

}


