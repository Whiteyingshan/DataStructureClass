#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;
bool use[10000];
int point[100000];
int nex[100000];

vector <P> v;

int main() {
    int s, n;
    cin >> s >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        point[a] = b;
        nex[a] = c;
    }

    printf("%05d %d ", s, point[s]);
    use[abs(point[s])] = true;
    for (int i = nex[s]; i != -1; i = nex[i]) {

        while (i != -1 && use[abs(point[i])]) {
            v.push_back(P(point[i], i));
            i = nex[i];
        }
        if (i == -1)
            break;
        use[abs(point[i])] = true;
        printf("%05d\n%05d %d ", i, i, point[i]);
    }
    printf("-1\n");
    if (v.size() != 0) {
        printf("%05d %d ", v[0].second, v[0].first);
        for (int i = 1; i < v.size(); i++)
            printf("%05d\n%05d %d ", v[i].second, v[i].second, v[i].first);
        printf("-1\n");
    }

    return 0;
}
