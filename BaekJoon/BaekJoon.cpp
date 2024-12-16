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
================= 2024-12-16================
[코테 강의 2주차 그래프이론, BFS, DFS]  2583번 영역 구하기 
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<vector<int>>field;
vector<vector<bool>>visited;

void fillField(pair<int, int> left, pair<int, int> right) {
	for (int i = left.second; i < right.second; ++i) {
		for (int j = left.first; j < right.first; ++j) {
			visited[i][j] = true;
		}
	}
}

int dirX[4] = { 1,0,0,-1 };
int dirY[4] = { 0,1,-1,0 };

void DFS(int x, int y,int w,int h,int& cnt) {

	if (!visited[y][x]) {
		cnt++;
		visited[y][x] = true;
	}

	for (int i = 0; i < 4; ++i) {
		int dx = x + dirX[i];
		int dy = y + dirY[i];
		if (dx >= 0 && dx < w && dy >= 0 && dy < h) {
			if (!visited[dy][dx]) {
				DFS(dx, dy, w, h, cnt);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int Y, X, N;
	cin >> Y >> X >> N;

	field.resize(Y, vector<int>(X, 0));
	visited.resize(Y, vector<bool>(X, false));

	for (int i = 0; i < N; ++i) {
		pair<int, int> left, right;
		cin >> left.first >> left.second >> right.first >> right.second;
		fillField(left, right);
	}

	vector<int> answer;
	int cnt{};
	for (int i = 0; i < Y; ++i) {
		for (int j = 0; j < X; ++j) {
			int size{};
			if (!visited[i][j]) {
				cnt++;
				DFS(j, i, X, Y, size);
			}
			if (size > 0)answer.push_back(size);
		}
	}
	sort(answer.begin(), answer.end());
	cout << cnt << '\n';
	for (int a : answer) {
		cout << a << ' ';
	}






}

