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
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-28================
17298번 오큰수
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int>st;
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}
	int max = -1;
	vector<int> answer(N,-1);
	for (int i = 0; i < N; ++i) {
		
		while (!st.empty() && vec[st.top()] < vec[i]) {
			answer[st.top()]=(vec[i]);
			st.pop();
		}
		st.push(i);
	}

	for (auto a : answer) {
		cout << a << ' ';
	}

}


