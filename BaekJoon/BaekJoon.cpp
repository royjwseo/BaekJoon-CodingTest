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
[실패 문제] 5430번 AC

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		string input;
		cin >> input;

		int n;
		cin >> n;

		string nums;
		cin >> nums;
		nums=nums.substr(1, nums.size() - 2);
		deque<int> factors;
		if (!nums.empty()) {
			stringstream ss(nums);	
			string real_num;
			while (getline(ss, real_num, ',')) {
				factors.push_back(stoi(real_num));
			}
		}
		

		bool isError = false;
		bool isReverse = false;
		for (char c : input) {
			if (c == 'R') {
				isReverse = !isReverse;
			}
			else {
				if (factors.empty()) {
					isError = true;
					break;
				}
				if (!isReverse) {
					factors.pop_front();
				}
				else {
					factors.pop_back();
				}
			}
		}
		
		if (!isError) {
			if (!isReverse) {
				cout << '[';
				for (auto it = factors.begin(); it != factors.end(); ++it) {
					if (it != factors.begin()) {
						cout << ',';
					}
					cout << *it;
				}
				cout << "]\n";
			}
			else {
				cout << '[';
				for (auto it = factors.rbegin(); it != factors.rend(); ++it) {
					if (it != factors.rbegin()) {
						cout << ',';
					}
					cout << *it;
				}
				cout << "]\n";
			}
		}
		else {
			cout << "error\n";
		}
	}

}


