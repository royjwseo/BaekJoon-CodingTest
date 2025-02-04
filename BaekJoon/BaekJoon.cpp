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
================= 2025-02-04================
[이분 탐색 복습] 2776번 암기왕 
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N;
		vector<int>note1(N);
		for (int i = 0; i < N; ++i)cin >> note1[i];
	
		cin >> M;
		vector<int>note2(M);
		for (int i = 0; i < M; ++i)cin >> note2[i];

		sort(note1.begin(), note1.end());

		for (auto a : note2) {
			if (upper_bound(note1.begin(), note1.end(), a) - lower_bound(note1.begin(), note1.end(), a)) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
	}
}

