#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-21================
- 백준 
24313번 알고리즘 수업 - 점근적 표기 1
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int a1, a0;
	int c;
	int n0;
	cin >> a1 >> a0 >> c >> n0;

	if (c * n0 >= a1 * n0 + a0&&c>=a1)cout << 1;
	else cout << 0;

}


