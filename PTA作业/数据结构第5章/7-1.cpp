//
// Created by Whiteying on 2019/10/22.
//

#include <bits/stdc++.h>

#include <utility>

using namespace std;
const int MAXN = 500 + 7, INF = 0x7f7f7f7f;

int n, cur;
string s, t, a[MAXN];
int b[MAXN];

struct node {
    string name;
    int f{};
    vector<node> vec;

    node() = default;

    node(string string1, int f_) {
        name = move(string1);
        f = f_;
    }

    bool operator<(const node &n2) const {
        if (f == n2.f) return name < n2.name;
        return f > n2.f;
    }
} root;


void add(node &no, int pos, int cnt) {
    if (pos == cnt) return;
    int i;
    for (i = 0; i < (int) no.vec.size(); ++i) {
        if (no.vec[i].name == a[pos]) {
            add(no.vec[i], pos + 1, cnt);
            return;
        }
    }
    node tt = node(a[pos], b[pos]);
    no.vec.push_back(tt);
    add(no.vec[i], pos + 1, cnt);
}

void init() {
    cin >> n;
    cin.get();
    root.name = "root";
    root.f = 1;
    root.vec.clear();
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        int f_ = 0;
        if (s[s.size() - 1] == '\\') f_ = 1;

        for (char &j : s)
            if (!isalpha(j)) j = ' ';
        stringstream ss(s);
        cur = 0;
        while (ss >> t) {
            a[cur] = t;
            b[cur++] = 1;
        }
        if (!f_) b[cur - 1] = 0;
        add(root, 0, cur);
    }
}

void dfs(node no, int cnt) {
    for (int i = 0; i < cnt; ++i)
        cout << "  ";
    cout << no.name << endl;
    sort(no.vec.begin(), no.vec.end());
    for (const auto &i : no.vec) {
        dfs(i, cnt + 1);
    }
}

int main() {
    init();
    dfs(root, 0);
    return 0;
}

