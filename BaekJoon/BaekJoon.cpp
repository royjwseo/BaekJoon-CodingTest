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
================= 2024-12-28================
[2주차그래프이론,DFS, BFS] 1992 쿼드트리
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<char>>board;

string conquer(int y, int x, int size) {

	if (size == 1)return string(1, board[y][x]);
	char first = board[y][x];

	string result = "";
	for (int i = y; i < size+y; ++i) {
		for (int j = x; j < x+size; ++j) {
			if (board[i][j] != first) {
				result += '(';
				result += conquer(y, x, size / 2);
				result += conquer(y, x + size / 2, size / 2);
				result += conquer(y + size / 2, x, size / 2);
				result += conquer(y + size / 2, x+size/2, size / 2);
				result += ')';
				return result;
			}
		}
	}
	return string(1, board[y][x]);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	board.resize(N, vector<char>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}

	cout << conquer(0, 0, N);

}

