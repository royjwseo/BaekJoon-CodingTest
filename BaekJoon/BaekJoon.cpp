#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-19 ================
- 백준 
11728번 배열 합치기

들어있는 수 10억 이하 int사용가능


*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*int N, M;
	cin >> N>> M;
	vector<int> my_array(N+M);
	for (int i = 0; i < N + M; ++i)cin >> my_array[i];

	sort(my_array.begin(), my_array.end());


	for (auto a: my_array) {
		cout << a << ' ';
	}
	//시간 복잡도 (N+M)log(N+M)
	*/

	int N, M;
	cin >> N >> M;
	vector<int> array1(N);
	vector<int> array2(M);
	for (int i = 0; i < N; ++i) {
		cin >> array1[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> array2[i];
	}
	vector<int>finalarray;
	int left_array1 = 0;
	int left_array2 = 0;
	while (left_array1+left_array2 < N+M) {

		if (left_array1 == N) {
			finalarray.push_back(array2[left_array2]);
			left_array2++;
		}
		else if (left_array2 == M) {
			finalarray.push_back(array1[left_array1]);
			left_array1++;
		}
		else 
		if (array1[left_array1] < array2[left_array2]) {
			finalarray.push_back(array1[left_array1]);
			left_array1++;
		}
		else {
			finalarray.push_back(array2[left_array2]);
			left_array2++;
		}

	}
	for (auto a : finalarray) {
		cout << a << ' ';
	}

}


