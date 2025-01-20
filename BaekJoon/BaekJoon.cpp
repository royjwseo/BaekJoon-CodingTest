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
================= 2025-01-20================
[이분 탐색(실패)] 1300번 K번째 수
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

/*
행렬 원소 값의 정의:
행렬𝐴[𝑖][𝑗]
A[i][j]는 (𝑖+1)×(𝑗+1)
(i+1)×(j+1)로 정의됩니다.
예를 들어, 행렬의 원소
𝐴[𝑖][𝑗]=(𝑖+1)×(𝑗+1)
A[i][j]=(i+1)×(j+1)입니다.
countLessOrEqual(n, x) 함수:
countLessOrEqual(n, x)는 주어진 수 x 이하인 모든 행렬 원소의 개수를 구하는 함수입니다.

각 행에서 x 이하인 원소 개수 구하는 공식
각 행𝑖 i에서 x 이하인 원소의 개수는 다음과 같습니다:
count_in_row(𝑖,𝑥)=min⁡(𝑥/𝑖,𝑛)
count_in_row(i,x)=min(x/i,n)
*/

long long cnt(int n, long long x) {
	long long count{};
	for (int i = 1; i <= n; ++i) {
		count += min(x / i, (long long)n);
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int K;
	cin >> K;
	long long left = 1;
	long long right = (long long)(N * N);
	long long ans;

	while (left <= right) {
		long long mid = (left + right) / 2;
		if (cnt(N, mid) >= K) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
}
// 1 2 3
// 2 4 6
// 3 6 9
