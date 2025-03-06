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
11727번 2xn 타일링 2
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int>dp(N+1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;//3
	dp[3] = 5;//5 1+2+2+
	dp[4] = 13;
	dp[5] = 23;
	for (int i = 3; i <= N; ++i) {
		
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;

	}
	cout << dp[N - 1];


}


