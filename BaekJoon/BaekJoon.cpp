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
================= 2024-12-31================
[2주차그래프이론,DFS, BFS] 17289 오큰수
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	stack<int>st;
	vector<int>answers(N,-1);

	for (int i = 0; i < N; ++i) {

		while(!st.empty()&&nums[st.top()] < nums[i]) {
			answers[st.top()] = nums[i];
			st.pop();
		}
		st.push(i);
	}

	for (auto a : answers) {
		cout << a << ' ';
	}
	
}

