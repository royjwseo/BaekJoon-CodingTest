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
[Dijikstra] 1261번 알고스팟
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>board;
vector<vector<int>>cost;
int N, M;
int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

void Dijikstra(int starty, int startx) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
	cost[starty][startx] = 0;
	pq.push({ 0,{starty,startx} });

	while (!pq.empty()) {
		pair<int, int>curCoord = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();
		if (curCost > cost[curCoord.first][curCoord.second])continue;

		for (int i = 0; i < 4; ++i) {
			int dx = curCoord.second + dirX[i];
			int dy = curCoord.first + dirY[i];
			if (dx > 0 && dy > 0 && dx <= M && dy <= N) {
				if (board[dy][dx] == 1) {
					if (cost[dy][dx] > cost[curCoord.first][curCoord.second] + 1) {
						cost[dy][dx] = cost[curCoord.first][curCoord.second] + 1;
						pq.push({ cost[dy][dx],{dy,dx} });
					}
				}
				else {
					if (cost[dy][dx] > cost[curCoord.first][curCoord.second]) {
						cost[dy][dx] = cost[curCoord.first][curCoord.second];
						pq.push({ cost[dy][dx],{dy,dx} });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> M >> N;
	board.resize(N+1,vector<int>(M+1,0));
	cost.resize(N+1,vector<int>(M+1,numeric_limits<int>::max()));

	
	for (int i = 1; i <= N; ++i) {
		string input;
		cin >> input;
		for (int j = 1; j <= M; ++j) {
			board[i][j] = input[j - 1]-'0';
		}
	}

	

	Dijikstra(1, 1);

	cout << cost[N][M];


}

