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
================= 2024-12-14================
[코테 강의 1주차 문자열,누적합,구현] 11655 ROT13
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	getline(cin, input);

	for (char& a : input) {
		if (islower(a)) {
			if (a <= 'z' && a >= 'a') {
				if (a + 13 > 'z') {
					a = 'a' + (a + 13 - 'z' - 1);
				}
				else {
					a = a + 13;
				}
			}
		}
		else {
			if (a <= 'Z' && a >= 'A') {
				if (a + 13 > 'Z') {
					a = 'A' + (a + 13 - 'Z' - 1);
				}
				else {
					a = a + 13;
				}
			}
		}
	}

	cout << input;
}

