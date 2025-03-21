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
================= 2025-03-21================
14501번 퇴사
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>>dates(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> dates[i].first >> dates[i].second;
	}
	vector<int>dp(N + 2);
	for (int i = 1; i <= N; ++i) {
		dp[i] = max(dp[i], dp[i-1]);
		if (i + dates[i].first <= N+1) {
		
			dp[i + dates[i].first] = max(dp[i+dates[i].first],dp[i]+dates[i].second);
		}
	}
	cout << *max_element(dp.begin(),dp.end());

}


