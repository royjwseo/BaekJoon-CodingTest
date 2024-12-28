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
[2주차그래프이론,DFS, BFS] 10709번 기상캐스터
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int H, W;
	cin >> H >> W;

	vector<vector<char>>map(H, vector<char>(W, 0));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> map[i][j];
		}
	}
	vector<vector<int>>answer(H, vector<int>(W, -1));

	for(int j=0;j<W;++j){
		for (int i = 0; i < H; ++i) {
			if (map[i][j] == 'c') { answer[i][j] = 0; 
				continue;
			}
			if (map[i][j] == '.'&&j==0)answer[i][j] = -1;

			if (j > 0) {
				if (map[i][j] == '.') {
					if (answer[i][j - 1] >= 0)answer[i][j] = answer[i][j - 1] + 1;
				}
			}
		}
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cout << answer[i][j] << ' ';
		}cout << '\n';
	}

}

