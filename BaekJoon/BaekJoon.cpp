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
================= 2025-03-06================
1003번 피보나치 함수
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
		int N;
		cin >> N;
		vector<vector<int>>dp(N+1,vector<int>(2));
		if (N == 0) { cout << 1 << ' ' << 0 << '\n'; continue; }
		if (N == 1) {
			cout << 0 << ' ' << 1 << '\n'; continue;
		}

		if (N > 1) {
			dp[0][0] = 1;
			dp[0][1] = 0;
			dp[1][0] = 0;
			dp[1][1] = 1;

			for (int i = 2; i <= N; ++i) {
				dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
				dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
			}
			cout << dp[N][0] << ' ' << dp[N][1] << '\n';
		}

		
	}

}


