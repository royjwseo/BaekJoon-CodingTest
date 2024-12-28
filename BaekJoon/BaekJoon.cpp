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
================= 2024-12-29================
[2주차그래프이론,DFS, BFS] 3474번 교수가 된 현우
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

using ll = unsigned long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int T;
	cin >> T;
	while (T--) {
		int input;
		cin >> input;
		int cnt{};
		
		for (int i = 5; i <= input; i *= 5) {
			cnt += input / i;
		}
		
		cout << cnt<<'\n';
	}

	

}

