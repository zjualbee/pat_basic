#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        pq.push(x);
    }
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + b;
        pq.push(c);
        sum += c;
    }
    cout << sum;
    return 0;
}
