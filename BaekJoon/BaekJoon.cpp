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
7785번 회사에 있는 사람

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	set<string> set;

	int N;
	cin >> N;
	while (N--) {
		string name, input;
		cin >> name >> input;
		if (input == "enter") {
			set.insert(name);
		}
		else {
			set.erase(name);
		}
	}
	
	vector<string> names(set.begin(), set.end());

	sort(names.begin(), names.end(), greater<string>());
	for (auto a : names) {
		cout << a << '\n';
	}

}


