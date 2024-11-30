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
1269번 대칭 차집합

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;
	cin >> A >> B;

	set<int> st;
	for (int i = 0; i < A + B; ++i) {
		int input;
		cin >> input;
		st.insert(input);
	}
	int diff = (A + B)-st.size();
	cout << (A + B) - 2 * diff;

}


