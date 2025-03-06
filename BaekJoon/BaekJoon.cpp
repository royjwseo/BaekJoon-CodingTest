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
2156번 포도주 시식
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int>wine(N);
	for (int i = 0; i < N; ++i)cin >> wine[i];
	vector<int>dp(N,-1);
	dp[0] = wine[0];
	if (N == 1) {
		cout << wine[0];
	}
	if (N == 2) {
		dp[1] = wine[1] + wine[0];
		cout << dp[1];
	}
	if (N >= 3) {
		
		dp[1] = wine[1] + wine[0];
		dp[2] = max({ wine[0] + wine[1],wine[2] + wine[0], wine[1] + wine[2] });
		for (int i = 3; i < N; ++i) {
			dp[i] = max({ dp[i - 1],dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i] });
		}
		cout << *max_element(dp.begin(), dp.end());
	}
}


