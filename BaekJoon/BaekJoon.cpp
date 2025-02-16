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
================= 2025-02-16================
2206번 벽 부수고 이동하기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int N, M;
vector<vector<int>>board;
vector<vector<vector<int>>>dist;

int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

void BFS() {
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	dist[0][0][0] = 1; //첫이 벽부쎴을때, 아닐때
	

	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int dx = cur.second + dirX[i];
			int dy = cur.first + dirY[i];
			if (dx >= 0 && dx < M && dy >= 0 && dy < N) {
				if (dist[dy][dx][0] == -1 || dist[dy][dx][1] == -1) {
					if (board[dy][dx] == 1) {
						if (dist[cur.first][cur.second][1] == -1) {
							dist[dy][dx][1] = dist[dy][dx][0] + 1;
							q.push({ dy,dx });
						}
					}
					else if (board[dy][dx] == 0) {
						if (dist[cur.first][cur.second][1] != -1) {
							dist[dy][dx][1] = dist[cur.first][cur.second][1] + 1;
							q.push({ dy,dx });
						}else if (dist[cur.first][cur.second][0] != -1) {
							dist[dy][dx][0] = dist[cur.first][cur.second][0] + 1;
							q.push({ dy,dx });
						}
					}
				
				}
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> N >> M;
	board.resize(N, vector<int>(M));
	dist.resize(N,vector<vector<int>>(M,vector<int>(2,-1)));
	
	for (int i = 0; i < N; ++i) {
		string input;
		cin >> input;
		for (int j = 0; j < M; ++j) {
			board[i][j] = input[j]-'0';
		}
	}

	BFS();




}


