#include <iostream>
#include <string>
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
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-28================
3190번 뱀
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int K;
	cin >> N >> K;
	vector<vector<int>>board(N+1, vector<int>(N+1));
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> y >> x;
		board[y][x] = 1;
	}
	int L;
	cin >> L;
	int sec{};
	int cur_dir = 0;
	int snake_x = 1, snake_y = 1;
	bool isGameOver = false;
	vector<int> after_sec(L,0);
	vector<char> directions(L);
	for (int i = 0; i < L; ++i) {
		cin >> after_sec[i];
		cin >> directions[i];
	}
	for (int i = L-1; i > 0; --i) {
		after_sec[i] -= after_sec[i - 1];
	}

	int index = 0;
	int left_sec{};
	int snake_len = 1;
	deque < pair<int, int> >snake_coord;
	snake_coord.push_back({ 1,1 });
	while (1) {
			if (index < L) {
				left_sec = after_sec[index];
			}
			else {
				left_sec = 10000;
			}
			while (left_sec--) {
				snake_y =snake_coord.front().second+ dirY[cur_dir];
				snake_x =snake_coord.front().first+ dirX[cur_dir];
				sec++;
				if (snake_y > N || snake_y<1 || snake_x>N || snake_x < 1 || board[snake_y][snake_x] == 2) {
					isGameOver = true;
					break;
				}


				if (board[snake_y][snake_x] != 1) {
					pair<int, int> tail = snake_coord.back();
					snake_coord.pop_back();
					board[tail.second][tail.first] = 0;
				}
				snake_coord.push_front({ snake_x,snake_y });
				board[snake_y][snake_x] = 2;
			}
			if (isGameOver) {
				break;
			}
			else {
				if (index < L) {
					if (directions[index] == 'D') {
						cur_dir = (++cur_dir + 4) % 4;
					}
					else {
						cur_dir = (--cur_dir + 4) % 4;
					}
				}
			}
			index++;
		}

	cout << sec;
	

}


