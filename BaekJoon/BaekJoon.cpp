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
================= 2025-01-12================
21937번 작업
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>adjacents;
vector<int>visited;

int DFS(int here) {

	int cnt{};
	if(!visited[here])
	visited[here] = true;
	
	for (int i = 0; i < adjacents[here].size(); ++i) {
		if (!visited[adjacents[here][i]]) {
			cnt++;
			cnt += DFS(adjacents[here][i]);
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int N, M;
	cin >> N >> M;
	adjacents.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; ++i) {
		int from, to;
		cin >> from >> to;
		adjacents[to].push_back(from);
	}
	
	int find;
	cin >> find;

	int ans = DFS(find);
	cout << ans;

}

