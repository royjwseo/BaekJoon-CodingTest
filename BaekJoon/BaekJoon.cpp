#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-14================
2164 카드 2
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int>cards;
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cards.push(i); //O(1) ->N번 O(N)
    }
     
    while (1) {
        if (cards.size() == 1)break;

        cards.pop();
        int front = cards.front();
        cards.pop();
        cards.push(front);
    }

    cout << cards.front();

}


