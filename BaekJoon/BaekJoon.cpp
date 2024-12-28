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
================= 2024-12-28================
[2주차그래프이론,DFS, BFS] 4659번 비밀번호 발음하기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

bool checkIf(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (1) {
		string input;
		cin >> input;
		if (input == "end")break;
		bool hasAnswer = true;
		if (input.find('a') != string::npos || input.find('e') != string::npos
			|| input.find('i') != string::npos || input.find('o') != string::npos
			|| input.find('u') != string::npos) {

			if (input.size() >= 2) {
				char a = input[0];
				for (int i = 1; i < input.size(); ++i) {
					if (input[i] == a && input[i] !='e'&&input[i]!='o') {
						cout << '<' << input << "> is not acceptable.\n";
						hasAnswer = false;
						continue;	
					}
					a = input[i];
				}
			}
			if (input.size() >= 3) {
				for (int i = 0; i < input.size() - 2; ++i) {
					int cnt{};
					string check = input.substr(i, 3);
					for (int j = 0; j < check.size(); ++j) {
						if (checkIf(check[j]))cnt++;
						else cnt--;
					}
					if (cnt == 3 || cnt == -3) {
						cout << '<' << input << "> is not acceptable.\n";
						hasAnswer = false;

						continue;
					}
				}
			}
			if(hasAnswer)
			cout << '<' << input << "> is acceptable.\n";
		}
		else {
			cout << '<' << input << "> is not acceptable.\n";
		}
	}

}

