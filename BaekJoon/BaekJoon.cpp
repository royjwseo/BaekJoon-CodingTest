#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-10 ================
- 백준 단계별로 풀어보기 일반 수학 1
2869번

달팽이-> V미터 높이 나무 막대 올라감
낮엔 A미터, 밤엔 B미터 미끄러짐, 정상에 도달시 미끄러지지X
나무막대 며칠걸리는지.

--해결 방안--

*/

int main() {
	int A{}, B{}, V{};
	cin >> A >> B >> V;

	int total_meter{};

	int one_Day_Up = A - B;
	int day_Cnt{};
	

	if (V - A > one_Day_Up) {
		day_Cnt += (V-A) / one_Day_Up+1;

	}	
	else
		day_Cnt = V / one_Day_Up + 1;
	
	cout << day_Cnt;
}


