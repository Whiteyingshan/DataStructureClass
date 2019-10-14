//
// Created by Whiteying on 2019/9/25.
//

#include <bits/stdc++.h>

using namespace std;
set<int> a;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (a.upper_bound(x) != a.end())
            a.erase(a.upper_bound(x));
        a.insert(x);
    }
    cout << a.size() << endl;
    return 0;
}