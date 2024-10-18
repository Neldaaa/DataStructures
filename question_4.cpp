#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void rearrangeQueue(queue<int> &q) {
    int n = q.size();
    stack<int> s;

    for (int i = 0; i < n / 2; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n / 2; i++) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < n / 2; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    rearrangeQueue(q);

    cout << "Rearranged queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
