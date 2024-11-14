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
18258번 큐 2
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;

    int N;
    cin >> N;

    string input;
    for (int i = 0; i < N; ++i) {
        cin >> input;

        if (input == "push") {
            int a;
            cin >> a;
            q.push(a);
        }
        else if (input == "front") {
            if (q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
            }
        }
        else if (input == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (input == "size") {
            cout << q.size() << '\n';
        }
        else if (input == "empty") {
            (q.empty()) ? cout<<"1\n" : cout<<"0\n";
        }
        else if (input == "back") {
            if (q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.back() << '\n';
            }
        }

    }


}


