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
================= 2025-01-18================
17413번 단어 뒤집기 2
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	getline(cin, input);

	bool put_in = true;
	bool reverse_pop = false;
	deque<char>dq;
	string ans = "";
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == '<') {
			put_in = false;
		}
		if (input[i] == '>') {
			put_in = true;
		}
		if (!put_in||i==input.size()-1)
		{
			if (i == input.size() - 1)dq.push_back(input[i]);
			while (!dq.empty()) {
				ans += dq.back();
				dq.pop_back();
			}
			if (i != input.size() - 1)
			ans += input[i];
		}
		else {
			if (input[i] == ' ') {
				while (!dq.empty()) {
					ans += dq.back();
					dq.pop_back();
				}
				ans += ' ';
			}
			else {
				if (input[i] == '>') {
					ans += '>';
					continue;
				}
				dq.push_back(input[i]);
			}
		}
		
	}
	cout << ans;

}

