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
2178 미로 탐색

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>> map;
vector<vector<bool>>visited;

int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

void BFS(int x, int y, int w, int h) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int dx = cur.first + dirX[i];
			int dy = cur.second + dirY[i];
			if (dx >= 0 && dy >= 0 && dx < w && dy < h) {
				if (!visited[dy][dx] && map[dy][dx] == 1) {
					visited[dy][dx]=true;
					map[dy][dx] = map[cur.second][cur.first] + 1;
					q.push({ dx,dy });
				}
			}
		}
	
	}
	cout << map[h - 1][w - 1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	map.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, false));

	string input;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		for (int j = 0; j < M; ++j) {
			int a = (int)(input[j] - '0');
			map[i][j] = a;
		}
	}

	
	BFS(0, 0, M, N);
	

}


