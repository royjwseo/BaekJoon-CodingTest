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
[DP] 9148번 신나는 함수 실행
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int dp[50][50][50];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)return 1;

	if (a > 20 || b > 20 || c > 20)return w(20,20,20);

	if (dp[a][b][c] != 0)return dp[a][b][c];

	if (a < b && b < c)return dp[a][b][c]=w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return dp[a][b][c]=w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}

}

