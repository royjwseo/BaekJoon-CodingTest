#include <iostream>
#include <string>
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
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-28================
9375번 패션왕 신해빈
경우의 수 -> 각 옷 종류 +1 (아무선택 X) 을 곱하여 -1(둘다 선택X)

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
		int cnt{};
		int N;
		cin >> N;
		unordered_map<string, int> clothes;
		for (int i = 0; i < N; ++i) {

			string wear;
			string which;
			cin >> wear >> which;
			clothes[which]++;
		}
		int result = 1;
		for (auto a : clothes) {
			result *= (a.second + 1);
		}
		cout << result - 1<<'\n';
		

	}
}


