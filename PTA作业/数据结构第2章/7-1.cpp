#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;
int point[100000];
int nex[100000];
int last[100000];

vector <P> v;

int main() {
    int s, n;
    int wei = -1;
    cin >> s >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        point[a] = b;
        nex[a] = c;
        if (c == -1)
            wei = a;
        else
            last[c] = a;
    }

    while (s != wei) {
        printf("%05d %d %05d\n", wei, point[wei], s);
        wei = last[wei];
        if (wei == s)
            break;
        printf("%05d %d %05d\n", s, point[s], wei);
        s = nex[s];
    }
    printf("%05d %d -1\n", s, point[s]);
    return 0;
}
