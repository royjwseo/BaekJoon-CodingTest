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
================= 2024-12-24================
[5주차 그리디,라인스위핑,투포인터] 9935 문자열 폭발
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	cin >> input;
	string cmp;
	cin >> cmp;

	string result = "";
	int cmp_len = cmp.length();
	for (char a : input) {
		result += a;
		if (result.size()>=cmp_len&&result.substr(result.size() - cmp_len) == cmp) {
			result.erase(result.size() - cmp_len);
		}
	}
	if (!result.empty()) {
		cout << result;
	}
	else {
		cout << "FRULA";
	}
	
}

