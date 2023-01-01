// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto num : tokens)
        {
            if (num == "+")
            {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                int val = x + y;
                st.push(val);
            }
            else if (num == "-")
            {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                int val = x - y;
                st.push(val);
            }
            else if (num == "*")
            {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                int val = x * y;
                st.push(val);
            }
            else if (num == "/")
            {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                int val = x / y;
                st.push(val);
            }
            else
            {
                st.push(stoi(num));
            }
        }
        return st.top();
    }
};