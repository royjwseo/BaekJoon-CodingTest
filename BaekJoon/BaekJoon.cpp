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
================= 2024-12-29================
[2주차그래프이론,DFS, BFS] 14502 연구소
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


vector<vector<int>>board;
vector<vector<int>>copyboard;
vector<pair<int,int>>coords;
vector<pair<int,int>>virus;
int N, M;
int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

void DFS(int y, int x) {

	for (int i = 0; i < 4; ++i) {
		int dx = x + dirX[i];
		int dy = y + dirY[i];
		if (dx >= 0 && dx < M && dy >= 0 && dy < N) {
			if (board[dy][dx] == 0) {
				board[dy][dx] = 2;
				DFS(dy, dx);
			}
		}
	}
}

int count() {
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == 0)cnt++;
		}
	}
	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> N >> M;

	board.resize(N, vector<int>(M,-1));
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 0)coords.push_back({ i,j });
			if (board[i][j] == 2)virus.push_back({ i,j });
		}
	}
	copyboard = board;
	int ans{};
	for (int i = 0; i < coords.size(); ++i) {
		for (int j = i+1; j < coords.size(); ++j) {
			for (int k = j+1; k < coords.size(); ++k) {
				board[coords[i].first][coords[i].second] = 1;
				board[coords[j].first][coords[j].second] = 1;
				board[coords[k].first][coords[k].second] = 1;
				for (auto a : virus) {
					DFS(a.first, a.second);					
				}
				ans = max(ans, count());
				board = copyboard;
			}
		}
	}
	cout << ans;
	


}

