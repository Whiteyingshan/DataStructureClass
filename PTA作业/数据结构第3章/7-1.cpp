//
// Created by Whiteying on 2019/9/26.
//
#include<bits/stdc++.h>
using namespace std;
stack<char>st;
int main()
{
    string s;
    cin>>s;
    bool first=true;
    for(int i=0;i<s.length();i++)
    {
        if(i==s.length())
        {
            cout<<s[i]<<endl;
            break;
        }
        if(s[i]>='0'&&s[i]<='9'||s[i]=='.'||s[i]=='-'&&(i==0||s[i-1]=='(')||s[i]=='+'&&(i==0||s[i-1]=='('))
        {
            if(!first)
                cout<<" ";
            if(s[i]=='-')
                cout<<s[i++];
            if(s[i]=='+')
                i++;
            while(s[i]>='0'&&s[i]<='9'||s[i]=='.')
                cout<<s[i++];
            first=false;
        }
        if(s[i]=='*'||s[i]=='/'||s[i]=='(')
            st.push(s[i]);
        else if(s[i]==')')
        {
            while(true)
            {
                if(st.top()=='(')
                {
                    st.pop();
                    break;
                }
                cout<<" "<<st.top();
                st.pop();
            }
        }
        else if(s[i]=='+'||s[i]=='-')
        {
            while(!st.empty()&&st.top()!='(')
            {
                cout<<" "<<st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        cout<<" "<<st.top();
        st.pop();
    }
    return 0;
}


