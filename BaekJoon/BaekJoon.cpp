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
================= 2025-01-20================
[32068번 보물 찾기] KOI 2024 2차 초등부
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
		int L, R, S;
		cin >> L >> R >> S;
		
		int min = (abs(L-S) >= abs(R-S)) ? R-S : L-S;

		if (min < 0) {
			cout << abs(min) * 2 + 1 << '\n';
		}
		else {
			cout << min * 2<<'\n';
		}
	}


}

