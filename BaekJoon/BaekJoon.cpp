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
2493번 탑

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int,int>>tops(N);
	for (int i = 0; i < N; ++i) {
		cin >> tops[i].first;
		tops[i].second = i + 1;
	}

	stack<pair<int,int>> st;
	vector<int>answers;
	for (int i = 0; i < N; ++i) {
		
			while (!st.empty() && tops[i].first > st.top().first) {
				st.pop();
			}
			if (st.size() != 0) {
				answers.push_back(st.top().second);
			}
			else {
				answers.push_back(0);
			}
		
		st.push(tops[i]);
	}
	for (auto a : answers) {
		cout << a << ' ';
	}

}


