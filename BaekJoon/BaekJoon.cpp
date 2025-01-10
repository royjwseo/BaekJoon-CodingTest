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
================= 2025-01-10================
4485번 녹색 옷 입은 애가 젤다지?
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>board;
int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };
vector<vector<int>>dist;
int T;
vector<vector<pair<int, int>>>parent;

void Dijikstra(int startY,int startX) {

	priority_queue<tuple<int, int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
	pq.push({ board[startY][startX],startY,startX });
	dist[startY][startX] = board[startY][startX];
	parent[startY][startX] = { startY,startX };
	while (!pq.empty()) {
		int curNodeX = get<2>(pq.top());
		int curNodeY = get<1>(pq.top());
		int curDist = get<0>(pq.top());
		pq.pop();
		if (curDist > dist[curNodeY][curNodeX])continue;
		
		for (int i = 0; i < 4; ++i) {
			int dx = curNodeX + dirX[i];
			int dy = curNodeY + dirY[i];
			if (dx >= 0 && dx < T && dy>=0 && dy < T) {
				if (curDist + board[dy][dx] < dist[dy][dx]) {
					dist[dy][dx] = curDist + board[dy][dx];
					parent[dy][dx] = { curNodeY,curNodeX };
					pq.push({ dist[dy][dx], dy, dx });
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 1;

	while (1) {
		
		cin >> T;
		if (T == 0)break;

		board.assign(T, vector<int>(T, 0));
		dist.assign(T, vector<int>(T, numeric_limits<int>::max()));
		parent.assign(T, vector<pair<int, int>>(T, { 0,0 }));

		for (int i = 0; i < T; ++i) {
			for (int j = 0; j < T; ++j)cin >> board[i][j];
		}

		Dijikstra(0, 0);

		cout << "Problem " << cnt++ << ": " << dist[T - 1][T - 1] << '\n';
	}
	
}

