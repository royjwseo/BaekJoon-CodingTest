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
[2주차그래프이론,DFS, BFS] 10026번 적록색약
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>board;
vector<vector<int>>board2;
vector<vector<bool>>visited;
vector<vector<bool>>visited2;
int N;
int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

void DFS(int y, int x,vector<vector<bool>>& visited, vector<vector<int>>&board) {
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		int dx = x + dirX[i];
		int dy = y + dirY[i];

		if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
			if (!visited[dy][dx]&&board[dy][dx]==board[y][x]) {
				DFS(dy, dx,visited,board);
			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> N;

	board.resize(N, vector<int>(N,0));
	board2.resize(N, vector<int>(N,0));
	visited.resize(N, vector<bool>(N, false));
	visited2.resize(N, vector<bool>(N, false));

	char input{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> input;
			if (input == 'G') {
				board[i][j] = 1;
			}
			else if (input == 'B') {
				board[i][j] = 2;
				board2[i][j] = 2;
			}	
		}
	}

	int cnt1{}, cnt2{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				cnt1++;
				DFS(i, j, visited, board);
			}
			if (!visited2[i][j]) {
				cnt2++;
				DFS(i, j, visited2, board2);
			}
		}
	}
	cout << cnt1 << ' ' << cnt2;





}

