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
[2주차그래프이론,DFS, BFS] 2636 치즈
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>field;
vector<vector<bool>>visited;
vector<pair<int, int>>cheeze;
int X, Y;
int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,-1,1,0 };

void DFS(int y, int x) {

	visited[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		int dx = x + dirX[i];
		int dy = y + dirY[i];

		if (dx >= 0 && dx < X && dy >= 0 && dy < Y) {
			if (!visited[dy][dx]) {
				visited[dy][dx] = true;
				if (field[dy][dx] == 1) {
					cheeze.push_back({ dy,dx });
					field[dy][dx] = 0;
				}
				else {
					DFS(dy, dx);
				}
			}
		}
	}
}


bool checkIfAll() {
	for (int i = 0; i < Y; ++i) {
		for (int j = 0; j < X; ++j) {
			if (field[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> Y >> X;

	field.resize(Y, vector<int>(X, 0));
	visited.resize(Y, vector<bool>(X, 0));

	for (int i = 0; i < Y; ++i) {
		for (int j = 0; j < X; ++j) {
			cin >> field[i][j];
		}
	}

	int cnt{};
	while (1) {

		for (auto& a : visited) {
			fill(a.begin(), a.end(), false);
		}
		cheeze.clear();
		DFS(0, 0);
		cnt++;
		if (checkIfAll()) {
			cout << cnt << '\n';
			cout << cheeze.size();
			break;
		}
	}
}

