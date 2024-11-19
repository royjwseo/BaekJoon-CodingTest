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
================= 2024-11-17================
2667번 단지번호붙이기

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>> map;
vector<vector<bool>>visited;
int N;
int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

void DFS(int x, int y,int &cnt) {

	visited[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; ++i) {
		int dx = x + dirX[i];
		int dy = y + dirY[i];
		if (dx >= 0 && dy >= 0 && dx <N && dy < N) {
			if (map[dy][dx] == 1&&!visited[dy][dx]) {
				DFS(dx, dy, cnt);
			}			
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin >> N;

	
	map.resize(N);
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; ++i) {
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); ++j) {
			int a = (int)(input[j] - '0');
			map[i].push_back(a);
		}
	}

	int house_bunches = 0;
	vector<int>answer;
	

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j] && map[i][j] == 1) {
				house_bunches++;
				int cnt=0;
				DFS(j, i, cnt);
				answer.push_back(cnt);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << house_bunches<<'\n';
	for (auto a : answer) {
		cout << a << '\n';
	}
}


