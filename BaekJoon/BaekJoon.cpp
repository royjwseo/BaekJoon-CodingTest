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
[코테 강의 1주차 문자열,누적합,구현] 9996번 한국이 그리울 땐 서버에 접속하지
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	string pattern;
	cin >> pattern;

	string pat1{}, pat2{};
	bool check = false;
	for (int i = 0; i < pattern.size(); ++i) {
		if (pattern[i] == '*') { check = true; continue; }
		if (!check)pat1 += pattern[i];
		else pat2 += pattern[i];
	}
	int pat1size = pat1.size();
	int pat2size = pat2.size();

	for (int i = 0; i < N; ++i) {
		bool isresult = true;
		string input;
		cin >> input;
		if (input.size() < pat1size + pat2size) {
			cout << "NE\n";
			continue;
		}
		for (int i = 0; i < pat1.size(); ++i) {
			if (input[i] != pat1[i]) {
				isresult = false;
			}
		}
		for (int i = 0; i <pat2.size(); i++) {
			if (input[input.size() - pat2.size() + i] != pat2[i]) {
				isresult = false;
			}
		}
		if (!isresult) {
			cout << "NE\n";
		}
		else {
			cout << "DA\n";
		}
	}

}

