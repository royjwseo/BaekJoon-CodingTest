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
================= 2024-11-19================
1012번 유기농 배추

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>> map;
vector<vector<bool>> visited;

int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

void BFS(int x, int y, int w, int h) {

	queue<pair<int, int>>q;
	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int dx = cur.first + dirX[i];
			int dy = cur.second + dirY[i];
			if (dx >= 0 && dy >= 0 && dy < h && dx < w) {
				if (!visited[dy][dx] && map[dy][dx]) {
					visited[dy][dx] = true;
					q.push({ dx,dy });
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int width, height;
		cin >> width >> height;

		int amount;
		cin >> amount;

		visited.assign(height, vector<bool>(width, false));
		map.assign(height, vector<int>(width, 0));
		int x, y;
		for (int i = 0; i < amount; ++i) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		int cnt{};
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				if (!visited[i][j] && map[i][j]==1) {
					cnt++;
					BFS(j, i, width, height);
				}
			}
		}
		cout << cnt << '\n';
	
	
	}

}


