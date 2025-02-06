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
================= 2025-02-06================
[DP] 24416번 알고리즘 수업 - 피보나치 수 1
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

pair<int,int> fib(int n) {
	int cnt{};
	cnt++;
	if (n == 1 || n == 2)return {1,cnt};
	pair<int, int>fib1 = fib(n - 1);
	pair<int, int>fib2 = fib(n - 2);
	return {fib1.first + fib2.first,fib1.second+fib2.second};
}

pair<int,int> fibonacci(int n) {
	vector<int>f(n+1);
	int cnt{};
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		cnt++;
	}
	return { f[n],cnt };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cout << fib(n).second << ' ' << fibonacci(n).second;
}

