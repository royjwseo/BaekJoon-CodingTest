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
[이분 탐색 복습] 7795번 먹을 것인가 먹힐 것인가
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
		cin >> N >> M;

		vector<int>A(N), B(M);
		for (int i = 0; i < N; ++i)cin >> A[i];
		for (int i = 0; i < M; ++i)cin >> B[i];

		sort(B.begin(), B.end());

		int cnt{};
		for (int i = 0; i < N; ++i) {
			
			int left = 0;
			int right = B.size();
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (B[mid] >=A[i]) {
					right = mid;
				}
				else {
					left = mid + 1;
				}
			}
			cnt += left;
		}
		cout << cnt<<'\n';
	}

}

