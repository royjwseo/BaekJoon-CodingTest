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
	
	deque<char> left;
	deque<char> right;

	for (char a : input) {
		left.push_back(a);
	}
	int exp = explosive.size();
	bool isSame = false;
	int cnt{};
	while (!left.empty()) {
		cnt = cnt % exp;
		char back = left.back();
		right.push_front(back);
		left.pop_back();
		
		if (back == explosive[exp - 1 - cnt]) {
			isSame = true;	
		}
		else {
			isSame = false;
		}
		
		if(!isSame){
			if (cnt > 0) {
				for (int i = 0; i < cnt; ++i) {
					if (!right.empty()) {
						left.push_back(right.front());
						right.pop_front();
					}
				}
			}
			cnt = 0;
		}
		else {
			cnt++;
			if (cnt == exp) {
				for (int i = 0; i < exp; ++i) {
					right.pop_front();
				}
				for (int i = 0; i < exp - 1; ++i) {
					if (!right.empty()) {
						left.push_back(right.front());
						right.pop_front();
					}
				}
			}

		}
		
	}

	string ans = "";
	for (auto a : right) {
		ans = ans + a;
	}
	if (ans.empty()) {
		cout << "FRULA";
	}
	else {
		cout << ans;
	}
}

