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
1352 효율적인 해킹

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>adjacents;
vector<bool>visited;

void DFS(int here,int& cnt) {

	visited[here] = true;
	cnt++;
	int size = adjacents[here].size();
	for (int i = 0; i < size; ++i) {
		int next = adjacents[here][i];
		if (!visited[next]) {
			DFS(next,cnt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	adjacents.resize(N+1);
	visited.resize(N+1,0);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adjacents[b].push_back(a);
	}
	vector<pair<int,int>>answer(N + 1);
	for (int i = 1; i <= N; ++i) {
		int cnt{};
		visited.assign(N + 1, false);
		DFS(i,cnt);
		answer[i].first = cnt;
		answer[i].second = i;
	}
	sort(answer.begin(), answer.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first)return a.second < b.second;
		return a.first > b.first;
		});
	for (int i = 0; i < answer.size(); ++i) {
		if (answer[i].first == answer[0].first) {
			cout << answer[i].second << ' ';
		}
	}
	

}

