#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

/*
================= 2024-10-25================
10828번 스택

*/

template<class T>
class STACK {
public:
   const void push(const T& value) {
        _container.push_back(value);
        cur_size++;
    }
   const void pop() {
        top();
        if (cur_size >= 0) {
            _container.pop_back();
            cur_size--;
        }
    }
    const void top() const{
        if (cur_size < 0) {
            cout << "-1\n";
        }
        else {
            cout << _container[cur_size] << '\n';
        }
        
    }
   const void empty()const {
        if (cur_size < 0) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }

    const void size()const {
        cout<< cur_size+1<<'\n';
    }

private:
    vector<T> _container;
    int cur_size=-1;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   

    STACK<int> MY_STACK;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;

        if (command == "push") {
            int a;
            cin >> a;
            MY_STACK.push(a);
        }
        else if (command == "top") {
            MY_STACK.top();
        }
        else if (command == "size") {
            MY_STACK.size();
        }
        else if (command == "empty") {
            MY_STACK.empty();
        }
        else if (command == "pop") {
            MY_STACK.pop();
        }
    }
   
 
   
}


