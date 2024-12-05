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
================= 2024-12-05================
[이진 탐색] 1920번 수 찾기

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

bool isFind(int num,vector<int>& num_list) {

	int right = num_list.size();
	int left = 0;
	int cur_index{};
	while (left<right) {
		 cur_index = (left + right) / 2;
		if (num > num_list[cur_index]) {
			left = cur_index+1;
		}
		else if(num<num_list[cur_index]) {
			right = cur_index - 1;
		}
		else {
			return true;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;

	vector<int>nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	int M;
	cin >> M;
	vector<int>find(M );
	for (int i = 0; i < M; ++i) {
		cin >> find[i];
	}

	for (int a : find) {
		if (isFind(a,nums)) {
			cout << 0 << '\n';
		}
		else {
			cout << 1 << '\n';
		}
	}





	

}

