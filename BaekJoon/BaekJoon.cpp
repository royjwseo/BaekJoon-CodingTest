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
5073번 삼각형과 세 변



*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	array<int, 3>tri{};
	while (1) {
		cin >> tri[0] >> tri[1] >> tri[2];
		if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0)break;

		sort(tri.begin(), tri.end());

		if (tri[2] >= tri[0] + tri[1])cout << "Invalid\n";
		else {
			if ((tri[0] == tri[1]) && (tri[1] == tri[2]) && (tri[0] == tri[2])) cout << "Equilateral\n";
			else if ((tri[0] != tri[1]) && (tri[1] != tri[2]) && (tri[0] != tri[2])) cout << "Scalene\n";
			else cout << "Isosceles\n";
		}
		

	}

	
}


