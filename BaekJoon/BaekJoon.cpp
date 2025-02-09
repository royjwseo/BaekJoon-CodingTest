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
================= 2025-02-09================
[DP] 1932번 정수 삼각형
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

/*
==Dynamic Programming==

1단계 작은 문제부터 직접 풀어보기
DP는 규칙을 찾는 게 핵심이야.
먼저 N=1,2,3,4 정도까지 경우를 직접 계산하면서 패턴을 찾아봐!

2단계: 점화식(재귀식) 만들기
규칙을 찾았으면, 이전 값들로 현재 값을 만들 수 있는 방법을 찾아 점화식을 세운다.
점화식이 안 떠오르면 "마지막에 무엇을 붙일 수 있는가?" 를 고민하면 돼!

3단계: 배열을 활용해 반복문으로 구현하기
점화식을 찾았으면, 이제 for 문을 사용해서 배열을 채우는 방식으로 구현하면 돼.
DP는 메모이제이션(Memoization) 을 활용해서 중복 계산을 방지하는 게 핵심이야.

4단계: 공간 최적화 가능하면 최적화하기
위 코드에서 dp 배열을 사용했지만, 사실 피보나치는 이전 두 개의 값만 사용하니까 배열 없이도 구현 가능해!
*/




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>>nums(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			int input;
			cin >> input;
			nums[i].push_back(input);
		}
	}
	
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; ++j) {
			nums[i][j] = nums[i][j] + max(nums[i + 1][j], nums[i + 1][j + 1]);
		}
	}
	cout << nums[0][0];
}



