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
================= 2025-03-21================
14503 로봇 청소기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/
int N, M;
vector<vector<int>>board;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;
	board.resize(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
		}
	}
	int cur_direction = d;
	pair<int, int>coord = { r,c };
	int cnt{};
	// 방향 인덱스: 0:북, 1:동, 2:남, 3:서
	int dirY[4] = { -1, 0, 1, 0 }; // y: 북, 동, 남, 서
	int dirX[4] = { 0, 1, 0, -1 }; // x: 북, 동, 남, 서

	while (1) {
		if (board[coord.first][coord.second] == 0) {
			cnt++;
			board[coord.first][coord.second] = 2;
		}
		bool needToCleanNear = false;
		pair<int, int>frontcoord, backcoord;
		for (int i = 0; i < 4; ++i) {
			cur_direction = (cur_direction + 3) % 4;  // 반시계 회전

			int dy = coord.first + dirY[cur_direction];
			int dx = coord.second + dirX[cur_direction];
			if (board[dy][dx] == 0) {
				// 0- 동 , 1-남  3-서
				needToCleanNear = true;
				frontcoord = { dy,dx };
				break;
			}
		}
		if (needToCleanNear) {
			coord = frontcoord;
			continue;
		}
		else {
			coord.first = coord.first + dirY[(cur_direction + 2) % 4];
			coord.second = coord.second + dirX[(cur_direction + 2) % 4];
			if (board[coord.first][coord.second] == 1)break;
		}
	}
	cout << cnt;
}

