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
================= 2024-12-03================
[정수론] 1037 약수
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int cnt;
	cin >> cnt;
	vector<int>nums(cnt);
	for (int i = 0; i < cnt; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	
	cout << nums[0] * nums[cnt - 1];
	
}

