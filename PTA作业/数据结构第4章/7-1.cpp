//
// Created by Whiteying on 2019/10/14.
//
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        string t;
        cin >> t;
        int compear = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i + t.length() - 1] != t[t.length() - 1])
                continue;
            bool flag = true;
            for (int j = 0; j < t.length(); j++)
                if (s[i + j] != t[j]) {
                    flag = false;
                    break;
                }
            if (flag) {
                compear = i;
                break;
            }
        }
        if (compear == -1)
            cout << "Not Found" << endl;
        else {
            for (int i = compear; i < s.length(); i++)
                cout << s[i];
            cout << endl;
        }
    }
    return 0;
}
