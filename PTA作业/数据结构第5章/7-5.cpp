//
// Created by Whiteying on 2019/10/17.
//

#include<iostream>
#include<algorithm>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> que;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        que.push(p);
    }
    while (que.size() != 1) {
        int a = que.top();
        que.pop();
        int b = que.top();
        que.pop();
        ans += a + b;
        que.push(a + b);
    }
    cout << ans << endl;
    return 0;
}