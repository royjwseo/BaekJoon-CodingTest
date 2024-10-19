#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-19 ================
- 백준 
2003 수들의 합

0.5초


*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int>added_nums(N + 1, 0);//1부터사용
	int input;
	for (int i = 1; i < N+1; ++i) {
		cin >> input;
		added_nums[i] = added_nums[i - 1] + input;
	}

	int cnt{};

	int left = 0;
	int right = 1;

		while (right <= N) {
			int sum = added_nums[right] - added_nums[left];
			if (sum == M) {
				cnt++;
				left++;
			}
			else if (sum < M) {
				right++;
			}
			else if (sum > M) {
				left++;			
			}
			if (left == right)right++;
		}

	
	cout << cnt;
	

}


