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
14425번 문자열 집합
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	unordered_set<string> set;

	for (int i = 0; i < N; ++i) {
		string input;
		cin >> input;
		set.insert(input);
	}
	int cnt{};
	for (int i = 0; i < M; ++i) {
		string find_str;
		cin >> find_str;

		if (set.find(find_str) != set.end()) {
			cnt++;
		}
	}
	cout << cnt;

}


