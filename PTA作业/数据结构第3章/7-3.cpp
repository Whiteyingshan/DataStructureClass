//
// Created by Whiteying on 2019/9/25.
//

#include <bits/stdc++.h>

using namespace std;
queue<int> A, B;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t % 2)
            A.push(t);
        else
            B.push(t);
    }
    int num = 1;
    while (!A.empty() && !B.empty()) {
        if (num == n)
            cout << A.front() << endl;
        else
            cout << A.front() << " ";
        num++;
        A.pop();
        if (!A.empty()) {
            if (num == n)
                cout << A.front() << endl;
            else
                cout << A.front() << " ";
            num++;
            A.pop();
        }
        if (num == n)
            cout << B.front() << endl;
        else
            cout << B.front() << " ";
        num++;
        B.pop();
    }
    while (A.empty()) {
        while (!B.empty()) {
            if (num == n)
                cout << B.front() << endl;
            else
                cout << B.front() << " ";
            num++;
            B.pop();
        }
        break;
    }
    while (B.empty()) {
        while (!A.empty()) {
            if (num == n)
                cout << A.front() << endl;
            else
                cout << A.front() << " ";
            num++;
            A.pop();
        }
        break;
    }
    return 0;
}