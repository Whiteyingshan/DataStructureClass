//
// Created by Whiteying on 2019/10/22.
//
#include <bits/stdc++.h>

using namespace std;
map<string, string> GTree;
string s[70];

int cal_space(string str) {
    int cnt = 0;
    while (str[cnt++] == ' ');
    return cnt;
}

bool ok(string s1, const string &s2) {
    while (GTree[s1] != s2 && GTree[s1] != "GPY") {
        s1 = GTree[s1];
    }
    return GTree[s1] == s2;
}

int main() {
    int n, m;
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        int cnt = cal_space(str) - 1;
        if (cnt == 0) {
            GTree[str] = "GPY";
            s[0] = str;
        } else {
            string ss;
            for (int cnt1 = cnt; cnt1 < (int) str.size(); cnt1++) {
                ss += str[cnt1];
            }
            s[cnt] = ss;
            GTree[ss] = s[cnt - 2];
        }
    }
    while (m--) {
        string str, s1, s2, s3;
        getline(cin, str);
        for (char i : str) {
            if (i == ' ') break;
            s1 += i;
        }
        for (int i = (int) str.size() - 1; i >= 0; i--) {
            if (str[i] == ' ') break;
            s3 += str[i];
        }
        for (int i = (int) s3.size() - 1; i >= 0; i--) {
            s2 += s3[i];
        }
        if (str.find("child") != -1) {
            printf("%s\n", GTree[s1] == s2 ? "True" : "False");
        } else if (str.find("parent") != -1) {
            printf("%s\n", GTree[s2] == s1 ? "True" : "False");
        } else if (str.find("descendant") != -1) {
            printf("%s\n", ok(s1, s2) ? "True" : "False");
        } else if (str.find("ancestor") != -1) {
            printf("%s\n", ok(s2, s1) ? "True" : "False");
        } else {
            printf("%s\n", GTree[s1] == GTree[s2] ? "True" : "False");
        }
    }
}