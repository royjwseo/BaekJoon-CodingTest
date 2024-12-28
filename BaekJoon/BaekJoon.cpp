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
================= 2024-12-29================
[2주차그래프이론,DFS, BFS] 9012 괄호
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	

	int N;
	cin >> N;

	while (N--) {
		stack<char> st;
		string input;
		cin >> input;

		bool isAns = true;
		for (char a : input) {
			if (a == '(') {
				st.push(a);
			}
			else if(a==')') {
				if (!st.empty()) {
					st.pop();
				}
				else {
					isAns = false;
					break;
				}
			}
		}
		if (!st.empty())isAns = false;
	
		if (isAns) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}

