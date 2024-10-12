#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- 백준 11660 구간 합 2차원 구하기
시간 제한 1초 (1억 연산)
1<=N<=1024
1<=M<=10만
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>>added_numbers(N + 1, vector<int>(N + 1, 0)); //[0]에는 0, 1부터 누적 합 쓸것임
	vector<vector<int>>input_numbers(N + 1, vector<int>(N + 1, 0));
	int input{};

	//공식 : i,j는 1부터 유효 수 -> 
	//added_numbers[i][j]= added_numbers[i-1][j] + added_numbers[i][j-1] - added_numbers[i-1][j-1] + input_numers[i][j]
	// 합 배열에서 중복 수 빼고 기존 배열 더하면 새로운 i,j 합배열 원소 구할 수 있고, 이게 최초 1열, 1행에도 적용됨 나머지가 0으로 초기화 되므로

	
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> input_numbers[i][j];
				added_numbers[i][j] = added_numbers[i][j - 1] + added_numbers[i - 1][j] - added_numbers[i - 1][j - 1] + input_numbers[i][j];
			}
		}

		int x1, x2, y1, y2;
		for (int i = 0; i < M; ++i) {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << added_numbers[x2][y2] - added_numbers[x1-1][y2] - added_numbers[x2][y1 - 1] + added_numbers[x1 - 1][y1- 1]<<'\n';
		}



}


