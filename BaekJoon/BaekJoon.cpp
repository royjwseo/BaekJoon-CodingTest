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
#include <map>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-28================
9935번 문자열 폭발

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	cin >> input;
	string explosive;
	cin >> explosive;
	while (1) {
		auto p = input.find(explosive);
		if (p == string::npos) {
			break;
		}
		input.erase(p, explosive.size());
	}
	if (input.empty()) {
		cout << "FRULA";
	}
	else {
		cout << input;
	}
}


