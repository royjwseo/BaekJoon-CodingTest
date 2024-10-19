#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-14 ================
- 백준 
1253 좋은 수 구하기

정렬 + 투 포인터

*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int>nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	int start = 0;
	int end = N - 1;
	int cnt{};
	int find={};

	for(int i=0;i<N;++i){
		start = 0;
		end = N - 1;
		find = nums[i];
		while (start < end) {
			if (start == find) start++;
			else if (end == find)end--;
			else if (nums[start] + nums[end] == find && start != find && end != find) {
				cnt++;
				break;
			}
			else if (nums[start] + nums[end] > find) {
				end--;
			}
			else if (nums[start] + nums[end] < find) {
				start++;
			}
		}
		

	}
	cout << cnt;


}


