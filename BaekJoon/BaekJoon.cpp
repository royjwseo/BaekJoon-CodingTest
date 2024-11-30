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
10845번 큐

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	queue<int> q;
	while (N--) {
		string input;
		cin >> input;
		if (input == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (input == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else
				cout << -1 << '\n';
		}
		else if (input == "size") {
			cout << q.size() << '\n';
		}
		else if (input == "empty") {
			(q.empty()) ? cout << "1\n" : cout << "0\n";
		}
		else if (input == "front") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else {
			if (q.empty()) {
				cout << "-1\n";
			}
			else
			{
				cout << q.back() << '\n';
			}
		}
	}

}


