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
[이분 탐색 복습] 1920번 수 찾기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


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
	for(int i=0;i<M;++i){
		int input;
		cin >> input;
		if (upper_bound(nums.begin(), nums.end(), input)-lower_bound(nums.begin(), nums.end(), input)) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}

	}

	
	
}

