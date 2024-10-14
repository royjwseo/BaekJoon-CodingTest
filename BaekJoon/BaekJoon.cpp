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
14215번 세 막대

a,b,c  최대한 길어야 함. 양의 정수, 줄일 수 잇음, 세 막대 이용해서 넓이가 양수

*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	array<int, 3> tri;
	cin >> tri[0] >> tri[1] >> tri[2];

	sort(tri.begin(), tri.end());

	if (tri[0] + tri[1] <= tri[2]) {
		tri[2] = tri[0] + tri[1] - 1;
	}
	int total{};
	for (int a : tri)total += a;
	cout << total;
}


