#include <iostream>
#include <string>
#include <numeric>
#include <sstream>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-12-28================
[2주차그래프이론,DFS, BFS] 2870번 수학숙제
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

struct compare {

	bool operator()(const string& a, const string& b) {
		if (a.size() == b.size())return a < b;
		else return a.size() < b.size();
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;

	vector<string>answer;
	while (N--) {
		string input;
		cin >> input;
	
		string result = "";
		bool curAlpha = true;
		for(int i=0;i!=input.size();++i){
			if (isdigit(input[i])) {
				if (result == "0")result = "";
				result += input[i];
				curAlpha = true;
			}
			else {
				curAlpha = false;
			}
			if (i == input.size() - 1 || !curAlpha) {
				if (!result.empty()) {
					answer.push_back(result);
					result = "";
				}
			}
		}
	}
	sort(answer.begin(), answer.end(),compare());
	for (auto a : answer) {
		cout << a << '\n';
	}

}

