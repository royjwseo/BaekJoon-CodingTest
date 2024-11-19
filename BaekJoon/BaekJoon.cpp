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

void DFS(int x, int y,int w,int h) {
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		int dx = x + dirX[i];
		int dy = y + dirY[i];
		if (dx >= 0 && dy >= 0 && dx < w && dy < h) {
			if (!visited[dy][dx] && map[dy][dx] == 1) {
				DFS(dx, dy,w,h);
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
					DFS(j, i,width,height);
				}
			}
		}
		cout << cnt << '\n';
	
	
	}

}


