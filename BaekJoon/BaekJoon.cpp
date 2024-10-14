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
9063번 대지


*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int x, y;
	int max_x=-10000, max_y=-10000, min_x=10000, min_y=10000;

	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		if (x > max_x)max_x = x;
		if (y > max_y)max_y = y;
		if (x < min_x)min_x = x;
		if (y < min_y)min_y = y;
	}
	cout << (max_x - min_x) * (max_y - min_y);
}


