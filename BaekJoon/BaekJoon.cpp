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
[2주차그래프이론,DFS, BFS] 7569번 토마토
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<vector<int>>>tomatoes;
vector<vector<vector<int>>>tomatoe_days;
vector<vector<vector<bool>>>visited;

int dirX[6] = { 0,0,1,-1,0,0 };
int dirY[6] = { 0,0,0,0,-1,1 };
int dirH[6] = { 1,-1,0,0,0,0 };
int M, N, H;

void BFS(queue<pair<int, pair<int, int>>>& q,int h, int y, int x) {
	visited[h][y][x] = true;


	while (!q.empty()) {
		pair<int, pair<int, int>> cur = q.front();
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int dx = cur.second.second + dirX[i];
			int dy = cur.second.first + dirY[i];
			int dh = cur.first + dirH[i];

			if (dx >= 0 && dx < M && dy >= 0 && dy < N && dh >= 0 && dh < H) {
				if (!visited[dh][dy][dx] && tomatoes[dh][dy][dx] == 0) {
					tomatoes[dh][dy][dx] = 1;
					tomatoe_days[dh][dy][dx] = tomatoe_days[cur.first][cur.second.first][cur.second.second] + 1;
					q.push({ dh,{dy,dx} });
				}
			}
		}
		
	}

}

int getMax() {
	int cnt{};
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				cnt= max(cnt, tomatoe_days[i][j][k]);
			}
		}
	}
	return cnt;
}

bool checkif() {
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (tomatoes[i][j][k] == 0)return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> M >> N >> H;

	tomatoes.resize(H, vector<vector<int>>(N, vector<int>(M)));
	tomatoe_days.resize(H, vector<vector<int>>(N, vector<int>(M)));
	visited.resize(H, vector<vector<bool>>(N, vector<bool>(M,false)));
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				cin >> tomatoes[i][j][k];
				if (tomatoes[i][j][k] == 1) {
					q.push({ i, { j,k } });
				}
			}
		}
	}
	
	if (checkif())cout << 0;
	else {
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < M; ++k) {
					if (tomatoes[i][j][k] == 1) {
						BFS(q,i, j, k);
					}
				}
			}
		}



		if (!checkif())cout << -1;
		else cout << getMax();
	}




}

