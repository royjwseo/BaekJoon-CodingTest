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
================= 2024-12-19================
[코테 강의 3주차 완전탐색]  4673번 셀프 넘버 
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<bool>check;

int CheckIfSelf(int i) {

	string test=to_string(i);
	int result = i;
	
	for (char a : test) {
		result += int(a - '0');
	}

	if (result > 10000)return 0;
	else 
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	check.resize(10001, false);

	
	for (int i = 1; i <= 10000; ++i) {
		check[CheckIfSelf(i)] = true;
	}

	for (int i = 1; i <= 10000; ++i) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}

}

