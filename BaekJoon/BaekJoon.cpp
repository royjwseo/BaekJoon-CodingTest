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
[Dijikstra] 11403 경로찾기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>adjacents;
vector<vector<bool>>visited;

vector<bool> GraphVisit(int start,int N) {

	vector<bool>visit(N,false);
	stack<int> st;

	for (int next : adjacents[start]) {
		st.push(next);
		visit[next] = true;
	}
	while (!st.empty()) {
		int top = st.top();
		st.pop();

		for (int next : adjacents[top]) {
			if (!visit[next]) {
				visit[next] = true;
				st.push(next);
			}
		}
	}
	return visit;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	adjacents.resize(N);
	visited.resize(N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int input;
			cin >> input;
			if (input == 1)
				adjacents[i].push_back(j);
		}
	}

	for (int i = 0; i < N; ++i) {
		visited[i] = GraphVisit(i, N);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}

}

