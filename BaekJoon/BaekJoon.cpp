#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-23================
1966번 프린터 큐

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		deque<pair<int, int>>dq;
		priority_queue<int> pq;
		int N;
		cin >> N;
		int ans;
		cin >> ans;

		for (int i = 0; i < N; ++i) {
			int input;
			cin >> input;
			pq.push({ input });
			dq.push_back({ input,i });
		}
		int cnt{};
		while (!pq.empty()) {
			int max = pq.top();
			pq.pop();
			cnt++;
			auto a = dq.front();
			while (1) {
				a = dq.front();	
				if (a.first == max)break;
				dq.push_back(a);
				dq.pop_front();
			}
			if (dq.front().second != ans) {
				dq.pop_front();
			}
			else {
				cout << cnt<<'\n';
				break;
			}
		}
		
		
	}
}


