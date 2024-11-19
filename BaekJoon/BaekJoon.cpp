#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-19================
1697 숨바꼭질

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

vector<bool>visited;
vector<int> seconds;
void BFS(int N,int M) {
	queue<int> q;
	visited[N] = true;
	q.push(N);
	while (!q.empty()) {
		int front = q.front();
		if (front == M) {
			return;
		}
		
		q.pop();
		for (int next:{front-1,front+1,front*2}) {
			
				if (next >= 0 && next < 100001) {
					if (!visited[next]) {
						visited[next] = true;
						q.push(next);
						seconds[next] = seconds[front] + 1;
					}
				}
			
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int K;
	cin >> N >> K;

	visited.resize(100001,false);
	seconds.resize(100001,0);
	if (N == K) {
		cout << 0 << '\n';
		return 0;
	}
	BFS(N,K);
	cout << seconds[K];
	
	

}


