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
================= 2024-12-03================
7576번 토마토
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>board;
vector<vector<bool>>visited;

int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

int BFS(vector<pair<int,int>> start,int max_x,int max_y) {
	queue<pair<int,int>> q;
	int cnt{};
	int result{};
	int once = start.size();
	int newtomato{};
	for (int i = 0; i < once; ++i) {
		q.push(start[i]);
		visited[start[i].first][start[i].second] = true;
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		cnt++;
		if (cnt > once) {
			result++;
			once += newtomato;
			newtomato = 0;
		}
		for (int i = 0; i < 4; ++i) {
			int dx = cur.second + dirX[i];
			int dy = cur.first + dirY[i];
			if (dx < max_x && dx >= 0 && dy < max_y && dy >= 0) {
				if (!visited[dy][dx]) {
					if (board[dy][dx] == -1) {
						visited[dy][dx] = true;
					}
					else if (board[dy][dx] == 0) {
						visited[dy][dx] = true;
						board[dy][dx] = 1;
						q.push({ dy, dx });
						newtomato++;
					}
				}
			}
		}

	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int x, y;
	cin >> x >> y;
	board.resize(y, vector<int>(x));
	visited.resize(y, vector<bool>(x, false));
	vector<pair<int, int>> start;
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				start.push_back({ i,j });
			}
		}
	}
	int res = BFS(start,x,y);
	bool isAll = true;
	for (int i = 0; i < y; ++i) {
		if (count(board[i].begin(), board[i].end(), 0)>0) {
			isAll = false;
			break;
		}	
	}
	if (isAll) {
		cout << res;
	}
	else {
		cout << -1;
	}
	
}

