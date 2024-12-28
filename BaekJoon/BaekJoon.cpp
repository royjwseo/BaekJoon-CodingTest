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
[2주차그래프이론,DFS, BFS] 2828 사과 담기 게임
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M,J;
	cin >> N >> M>>J;

	int cur_loc = 1;
	int cnt{};
	for (int i = 0; i < J; ++i) {
		int where;
		cin >> where;

		int left = cur_loc;
		int right = cur_loc + M - 1;

		if (where >= left && where <= right) {
			continue;
		}
		else {
			if (where > right) {
				cnt +=  where-right;
				cur_loc = where-M + 1;
			}
			else if (left > where) {
				cnt += left - where;
				cur_loc = where;
			}
		}

	}
	cout << cnt;
}

