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
================= 2024-12-19================
[완전탐색, 브루트포스]  1018번 체스판 다시 칠하기 
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int checkBoard_Bstart(vector<vector<char>>& board,int y, int x,int cur_min) {

	int cnt{};
	int check_cnt{};
	for (int i = y; i < y + 8; ++i) {
		for (int j = x; j < x + 8; ++j) {
			if (cnt >= cur_min)break;
			check_cnt++;
			if (check_cnt % 2 == 0) {
				if (board[i][j] == 'B')cnt++;
			}
			else {
				if (board[i][j] == 'W')cnt++;
			}
		}
		check_cnt++;
	}
	return cnt;
}

int checkBoard_Wstart(vector<vector<char>>& board, int y, int x, int cur_min) {

	int cnt{};
	int check_cnt{};
	for (int i = y; i < y + 8; ++i) {
		for (int j = x; j < x + 8; ++j) {
			if (cnt >= cur_min)break;
			check_cnt++;
			if (check_cnt % 2 == 0) {
				if (board[i][j] == 'W')cnt++;
			}
			else {
				if (board[i][j] == 'B')cnt++;
			}
		}
		check_cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M; //y->N x->M

	vector<vector<char>>board(N, vector<char>(M, '0'));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
		}
	}

	
	int check_width = M - 8 + 1;
	int check_height = N - 8 + 1;
	int min_result = N * M;
	for (int i = 0; i < check_height; ++i) {
		for (int j = 0; j < check_width; ++j) {
			min_result = min(min(checkBoard_Bstart(board, i, j, min_result), checkBoard_Wstart(board, i, j, min_result)), min_result);
		}
	}
	cout << min_result;


}

