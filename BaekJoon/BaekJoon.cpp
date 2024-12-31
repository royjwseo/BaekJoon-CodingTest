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
================= 2024-12-31================
[2주차그래프이론,DFS, BFS] 1325 효율적인 해킹
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>adjacents;
vector<int>visited;

int DFS(int here) {
	int cnt=1;
	if (!visited[here]) visited[here] = true;
	
	
		for (int a : adjacents[here]) {
			if (!visited[a])
				cnt += DFS(a);
		}
	
	return cnt;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	adjacents.resize(N+1);
	visited.resize(N + 1,0);
	for (int i = 0; i < M; ++i) {
		pair<int, int>input;
		cin >> input.first >> input.second;
		adjacents[input.second].push_back(input.first);
	}

	int max_res{};
	vector<pair<int,int>>result;
	for (int i = 1; i <= N; ++i) {
		int cnt{};
		fill(visited.begin(), visited.end(), 0);
		cnt = DFS(i);
		max_res = max(max_res, cnt);
		result.push_back({cnt,i});
	}

	sort(result.begin(), result.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
		if (l.first == r.first)return l.second < r.second;
		return l.first > r.first;
		});

	for (auto a : result) {
		if (a.first == max_res)cout << a.second << ' ';
	}



}

