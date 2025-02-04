#include <iostream>
#include <string>
#include <tuple>
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
================= 2025-02-04================
[구간 합] 2851 슈퍼 마리오 
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int>added_mushrooms(11);
	for (int i = 1; i <= 10; ++i) {
		int input;
		cin >> input;
		added_mushrooms[i] = added_mushrooms[i - 1] + input;
	}

	int ans=101;
	int res{};
	for (int i = 1; i <= 10; ++i) {
	
		if (abs(added_mushrooms[i] - 100) <= ans) {
			ans = min(ans, abs(added_mushrooms[i] - 100));
			res = added_mushrooms[i];
		}
		/*if (min(ans, abs(added_mushrooms[i] - 100)) != ans) {
			ans = min(ans, abs(added_mushrooms[i] - 100));
			res = added_mushrooms[i];
		}*/
	}
	cout << res;


}

