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
================= 2025-02-02================
[PCCP 기출문제] 3번 / 충돌위험 찾기 -> 실패함
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
	int answer = 0;

	int n = points.size();

	int n_robots = routes.size();
	vector<pair<int, int>>start(n_robots);
	vector<pair<int, int>>dest(n_robots);
	vector<pair<int, int>>robo_dist(n_robots);
	vector<vector<int>>cur_robots(101, vector<int>(101, 0));
	for (int i = 0; i < n_robots; ++i) {
		start[i].first = points[routes[i][0] - 1][0];
		start[i].second = points[routes[i][0] - 1][1];

		cur_robots[start[i].first][start[i].second]++;

		dest[i].first = points[routes[i][1] - 1][0];
		dest[i].second = points[routes[i][1] - 1][1];

		robo_dist[i] = { dest[i].first - start[i].first,	dest[i].second - start[i].second };
	}
	int cnt{};
	vector<bool>allDone(n_robots, false);
	while (1) {
		bool isFinished = true;

		for (int i = 1; i < 101; ++i) {
			for (int j = 1; j < 101; ++j) {
				if (cur_robots[i][j] > 1)cnt += 1;
			}
		}


		for (int i = 0; i < n_robots; ++i) {
			if (allDone[i] == false) {
				isFinished = false;
			}
		}
		if (isFinished) {
			break;
		}

		for (int i = 0; i < n_robots; ++i) {
			cur_robots[start[i].first][start[i].second]--;
			if (abs(robo_dist[i].first) != 0) {
				if (robo_dist[i].first > 0) {
					start[i].first += 1;
					robo_dist[i].first -= 1;
				}
				else {
					start[i].first -= 1;
					robo_dist[i].first += 1;
				}
				cur_robots[start[i].first][start[i].second]++;
			}
			else if (abs(robo_dist[i].second > 0)) {
				if (robo_dist[i].second > 0) {
					start[i].second += 1;
					robo_dist[i].second -= 1;
				}
				else {
					start[i].second -= 1;
					robo_dist[i].second += 1;
				}
				cur_robots[start[i].first][start[i].second]++;
			}
			else {
				allDone[i] = true;
			}
		}




	}
	answer = cnt;
	return answer;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//[[3, 2], [6, 4], [4, 7], [1, 4]],
		//[[4, 2], [1, 3], [4, 2], [4, 3]]
	
	vector<vector<int>>p(4, vector<int>(2));
	vector<vector<int>>r(4, vector<int>(2));

	p[0][0] = 3;
	p[0][1] = 2;
	p[1][0] = 6;
	p[1][1] = 4;
	p[2][0] = 4;
	p[2][1] = 7;
	p[3][0] = 1;
	p[3][1] = 4;
	
	r[0][0] = 4;
	r[0][1] = 2;
	r[1][0] = 1;
	r[1][1] = 3;
	r[2][0] = 4;
	r[2][1] = 2;
	r[3][0] = 4;
	r[3][1] = 3;

	cout<<solution(p, r);

	
}

