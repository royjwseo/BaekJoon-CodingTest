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
1021번 회전하는 큐
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int M;
	cin >> N >> M;

	deque<int> dq;
	for (int i = 1; i <= N; ++i) {
		dq.push_back(i);
	}
	int cnt{};
	for (int i = 0; i < M; ++i) {
		int input;
		cin >> input;

		auto it=find(dq.begin(), dq.end(), input);
		if (it - dq.begin() > dq.size() / 2) {
			while (dq.front() != input) {
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		else {
			while (dq.front() != input) {
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}
		dq.pop_front();
	}
	cout << cnt;

}


