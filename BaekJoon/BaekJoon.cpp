#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-14 ================
- ���� 
14215�� �� ����

a,b,c  �ִ��� ���� ��. ���� ����, ���� �� ����, �� ���� �̿��ؼ� ���̰� ���

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


