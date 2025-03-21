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
11052번 카드 구매하기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//아이디, 얼굴 -> 등급을 나타내는 색 8가지 
	// 카드팩형태 - 카드1개, 카드n개

	int N;
	cin >> N;

	vector<int>cards(N + 1);
	for (int i = 0; i < N; ++i)cin >> cards[i + 1];

	vector<int>dp(N + 1);
	if (N == 1) {
		dp[1] = cards[1];
		cout << cards[1];
	}
	else if (N == 2){
		dp[2] = max(cards[1] * 2, cards[2]);
		cout << dp[2];
	}else{
		dp[1] = cards[1];
		dp[2] = max(cards[1] * 2, cards[2]);
		for (int i = 3; i <= N; ++i) {
			if (i % 2 == 0) {
				dp[i] = max({ cards[i], dp[i/2] * 2,dp[i - 1] + dp[1] });
			}
			else {
				dp[i] = max({ cards[i], dp[i - 1] + dp[1],dp[i - 2] + dp[2] });
			}
		}
	}
	cout << dp[N];
	//5 10 15 20 35 50 85
}


