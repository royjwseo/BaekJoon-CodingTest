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
	
	int index = 1;
	string ans = "";
	for(char a: input) {
		ans = ans + a;
		if (ans.size() >= explosive.size()) {
			if (ans.substr(ans.size() - explosive.size(), explosive.size()) == explosive) {
				ans.erase(ans.size() - explosive.size(), explosive.size());
			}
		}
	}
	
	if (ans.empty()) {
		cout << "FRULA";
	}
	else {
		cout << ans;
	}
}

