#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- 백준 
3009번 네 번째 점.

세 점을 주고, 축에 평행한 직사각형 만들기 위한 마지막 점

*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x[3], y[3];
	for (int i = 0; i < 3; ++i) {
		cin >> x[i] >> y[i];

	}
	int result_x, result_y;
	if (x[0] == x[1])result_x = x[2];
	else if (x[1] == x[2])result_x = x[0];
	else if (x[2] == x[0])result_x = x[1];

	if (y[0] == y[1])result_y = y[2];
	else if (y[1] == y[2])result_y = y[0];
	else if (y[2] == y[0])result_y = y[1];

	cout << result_x << ' ' << result_y;
}


