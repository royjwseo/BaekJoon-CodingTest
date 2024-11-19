#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-19================
7562 나이트의 이동

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>> board;
vector<vector<bool>> visit;

pair<int, int>dir[8] = { {1,2},{2,1},{1,-2},{2,-1},{-1,-2},{-2,-1},{-2,1},{-1,2} };

void BFS(pair<int, int> here, pair<int, int> go,int I) {

	queue<pair<int, int>> q;
	q.push(here);
	visit[here.second][here.first] = true;

	while (!q.empty()) {

		pair<int, int> cur = q.front();
		q.pop();

		if (cur.second == go.second && cur.first == go.first)return;


		for (auto next : dir) {
			pair<int, int> next_coord = { cur.first + next.first,cur.second + next.second };

			if (next_coord.first < I && next_coord.first >= 0 && next_coord.second < I && next_coord.second >= 0) {
				if (!visit[next_coord.second][next_coord.first]) {
					visit[next_coord.second][next_coord.first] = true;
					q.push(next_coord);
					board[next_coord.second][next_coord.first] = board[cur.second][cur.first] + 1;
				}
			}

		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int I;
		cin >> I;

		board.assign(I, vector<int>(I, 0));
		visit.assign(I, vector<bool>(I, false));

		int here_x, here_y;
		cin >> here_x >> here_y;

		int go_x, go_y;
		cin >> go_x >> go_y;

		BFS({ here_x,here_y }, { go_x,go_y },I);

		cout << board[go_y][go_x]<<'\n';
	}

}


