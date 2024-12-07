#include <iostream>
#include <string>
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
================= 2024-12-07================
[이진 탐색] 2512번 예산

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int>money(N);
	for (int i = 0; i < N; ++i)cin >> money[i];

	int M;
	cin >> M;

	int min = 0;
	int max = *max_element(money.begin(), money.end());
	int result{};
	while (min <= max) {
		int cnt{};
		int mid = (min + max) / 2;

		for (int a : money) {
			if (mid >= a) {
				cnt += a;
			}
			else {
				cnt += mid;
			}
		}

		if (cnt > M) {			
			max = mid - 1;
		}
		else {	
			result = mid;
			min = mid + 1;
		}
	}
	cout << result;

}

