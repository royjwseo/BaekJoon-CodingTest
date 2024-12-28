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
[2주차그래프이론,DFS, BFS] 1436번 영화감독 숌
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int cnt{};
	for (int i = 666; i < numeric_limits<int>::max(); ++i) {
		string find_num = to_string(i);
		if (find_num.find("666")!=string::npos) {
			cnt++;
		}
		if (cnt == N) {
			cout << i;
			break;
		}
	}

}

