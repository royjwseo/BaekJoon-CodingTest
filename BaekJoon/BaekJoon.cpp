#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-20 ================
- 백준 
12891번
DNA 비밀번호


*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int S, P;

	cin >> S >> P;

	string DNA;
	cin >> DNA;

	int A, C, G, T;
	cin >> A >> C >> G >> T;

	int left = 0;
	int right = P;

	int A_count{}, C_count{}, G_count{}, T_count{};
	int cnt{};
	//while (right-1 < S) {
	//	A_count = count(DNA.begin() + left, DNA.begin() + right, 'A');
	//	C_count = count(DNA.begin() + left, DNA.begin() + right, 'C');
	//	G_count = count(DNA.begin() + left, DNA.begin() + right, 'G');
	//	T_count = count(DNA.begin() + left, DNA.begin() + right, 'T');
	//	if (A_count >= A && C_count >= C && G_count >= G && T_count >= T) {
	//		cnt++;
	//	}
	//	left++;
	//	right++;
	//}
	for (int i = 0; i < P; ++i) {
	if (DNA[i] == 'A') A_count++;
	else if (DNA[i] == 'C') C_count++;
	else if (DNA[i] == 'G') G_count++;
	else if (DNA[i] == 'T') T_count++;
}

// 첫 번째 윈도우가 조건을 만족하는지 확인
if (A_count >= A && C_count >= C && G_count >= G && T_count >= T) {
	cnt++;
}


	for (int i = P; i < S; ++i) {
		// 윈도우의 앞쪽 문자 제외
		if (DNA[i - P] == 'A') A_count--;
		else if (DNA[i - P] == 'C') C_count--;
		else if (DNA[i - P] == 'G') G_count--;
		else if (DNA[i - P] == 'T') T_count--;

		// 윈도우의 뒤쪽 문자 추가
		if (DNA[i] == 'A') A_count++;
		else if (DNA[i] == 'C') C_count++;
		else if (DNA[i] == 'G') G_count++;
		else if (DNA[i] == 'T') T_count++;

		// 새로운 윈도우가 조건을 만족하는지 확인
		if (A_count >= A && C_count >= C && G_count >= G && T_count >= T) {
			cnt++;
		}
	}
	cout << cnt;

}


