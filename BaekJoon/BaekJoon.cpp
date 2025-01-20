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
[2024 국민대학교 & 중앙대학교 연합 프로그래밍 경진대회 Open Contest]
32751번 햄버거
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	array<int, 4>ingredients;
	cin >> N >> ingredients[0] >> ingredients[1] >> ingredients[2] >> ingredients[3];
	string input;
	cin >> input;

	bool isFine = true;
	if (input[0] == 'a' && input[N - 1] == 'a'){
		for (int i = 0; i < 4; ++i) {
			int cnt = count(input.begin(), input.end(), (char)('a' + i));
			if (cnt > ingredients[i]) {
				isFine = false;
				break;
			}
		}
		char cur=input[0];
		for (int i = 1; i < N; ++i) {
			if (input[i] == cur) {
				isFine = false;
				break;
			}
			cur = input[i];
		}
		
	}
	else {
		isFine = false;
	}
	if (isFine)cout << "Yes";
	else cout << "No";

}

