#include<bits/stdc++.h>

using namespace std;
stack<double> st;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {

        if ((s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') ||
            s[i] == '-' && (s[i + 1] >= '0' && s[i + 1] <= '9')) {
            double num = 0;
            bool xiao = false;
            int point = 10;
            int j;
            for (j = i; j < s.length(); j++) {
                if (s[j] == ' ')
                    break;
                if (s[j] == '-')
                    continue;
                if (s[j] == '.') {
                    xiao = true;
                    continue;
                } else if (xiao) {
                    num += (double) (s[j] - '0') / point;
                    point *= 10;
                } else {
                    num *= 10;
                    num += (s[j] - '0');
                }
            }
            if (s[i] == '-')
                num = -num;
            i = j;
            st.push(num);
        } else {
            double a1 = st.top();
            st.pop();
            double a2 = st.top();
            st.pop();
            if (s[i] == '+') {
                a2 += a1;
                st.push(a2);
            } else if (s[i] == '-') {
                a2 -= a1;
                st.push(a2);
            } else if (s[i] == '*') {
                a2 *= a1;
                st.push(a2);
            } else if (s[i] == '/') {
                a2 /= a1;
                st.push(a2);
            }
            i++;
        }
    }
    while (!st.empty()) {
        printf("%.1f\n", st.top());
        st.pop();
    }
    return 0;
}
