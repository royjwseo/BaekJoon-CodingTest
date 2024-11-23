#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-23================
1764번 듣보잡

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int M;
	cin >> N >> M;

	set<string> s;
	vector<string> answer;
	for (int i = 0; i < N + M; ++i) {
		string input;
		cin >> input;

		set<string>::iterator It=s.find(input);
		if (It != s.end()) {
			answer.push_back(input);
		}
		s.insert(input);
	}
	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (auto a : answer) {
		cout << a << '\n';
	}
	
}


