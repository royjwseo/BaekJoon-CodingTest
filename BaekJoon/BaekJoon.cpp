#include <iostream>
#include <string>
#include <numeric>
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
================= 2024-12-02================
[그리디] 11047번 동전 0 

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	
	int N;
	int K;
	cin >> N >> K;

	vector<int>coins(N);
	for (int i = 0; i < N; ++i) {
		cin >> coins[i];
	}
	int total{};
	int index = N-1;
	while (1) {
		int cur_fund = K / coins[index];
		if (cur_fund < 1) {
			index--;
		}
		else {
			total += cur_fund;
			K -= coins[index] * cur_fund;
		}
		if (K <= 0) {
			break;
		}
	}
	cout << total;
}

