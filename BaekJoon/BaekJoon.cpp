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
================= 2024-12-16================
[코테 강의 2주차 그래프이론, BFS, DFS]  2468번 안전 영역
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

void DFS(int x,int y, vector<vector<bool>>&visited) {

	if(!visited[y][x])
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		int dx = x + dirX[i];
		int dy = y + dirY[i];
		if (dx >= 0 && dx < visited[0].size() && dy >= 0 && dy < visited[0].size()) {
			if (!visited[dy][dx]) {
				DFS(dx, dy, visited);
			}
		}
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>>map(N, vector<int>(N, 0));
	vector<vector<bool>>visited(N, vector<bool>(N, false));
	int min = 101;
	int max = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] < min) {
				min = map[i][j];
			}
			if (map[i][j] > max) {
				max = map[i][j];
			}
		}
	}

	int result{};
	for (int i = min; i <= max; ++i) {
		int cnt{};
		for(int u=0;u<N;++u)
		fill(visited[u].begin(), visited[u].end(), false);
		
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (map[j][k] < i) {
					visited[j][k] = true;
				}
			}
		}

		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (!visited[j][k]) {
					cnt++;
					DFS(k, j, visited);
				}
			}
		}
		if (cnt > result) {
			result = cnt;
		}
	}
	cout << result;




}

