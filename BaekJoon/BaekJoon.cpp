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
================= 2024-12-24================
[6주차 이분탐색 & LIS(최대증가부분수열)] 2792번 보석 상자
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int check(vector<int>&jewels,int division_num,int num_of_people) {

	int jewels_size = jewels.size();
	int cnt{};
	for (int i = 0; i < jewels_size; ++i) {
		int cur_num = jewels[i];
		int leftover= cur_num / division_num;
		cnt += leftover;
		if (cur_num % division_num)
			cnt++;			
	}
	return cnt <= num_of_people;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<int>jewels(M);
	int max_find = 0;
	for (int i = 0; i < M; ++i) {
		cin >> jewels[i];
		max_find = max(max_find, jewels[i]);
	}

	int left = 1;
	int right = max_find;
	int result = numeric_limits<int>::max();
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(jewels,mid,N)) {
			right = mid - 1;
			result = min(result, mid);
		}
		else {
			left = mid + 1;
		}
	}
	cout << result;
}

