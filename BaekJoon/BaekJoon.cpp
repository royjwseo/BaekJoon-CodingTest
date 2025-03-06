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
2579번 계단 오르기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int>stairs(N);
	for (int i = 0; i < N; ++i)cin >> stairs[i];
	vector<int>dp(N);
	if (N == 1) {
		dp[0] = stairs[0];
		cout << dp[0];
	}
	else if (N == 2) {
		dp[1] = stairs[1]+stairs[1];
		cout << dp[1];
	}
	else {
		dp[0] = stairs[0];
		dp[1] = stairs[0] + stairs[1];
		dp[2] = max(dp[1], dp[0] + stairs[2]);
		for (int i = 3; i < N; ++i) {
			dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3]+stairs[i-1]+stairs[i]);
		}
	}

	//10->15->25 / 10->20->25(전단계에서 안밟음) / 10->15->10 안밟음 

	cout << dp[N - 1];
}


