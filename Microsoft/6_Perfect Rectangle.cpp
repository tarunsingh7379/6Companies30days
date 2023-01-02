// https://leetcode.com/problems/perfect-rectangle/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

// Approach
// 1. sum of all small rectangles area should be equal to the whole rectangle area.
// 2. set should contain only four points that contribute to the whole rectangle area.

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN;
        long long int area = 0;
        set<string> st;
        for (auto num : rectangles)
        {
            x1 = min(x1, num[0]);
            y1 = min(y1, num[1]);
            x2 = max(x2, num[2]);
            y2 = max(y2, num[3]);
            area = area + 1LL * (num[2] - num[0]) * (num[3] - num[1]);
            string s1 = to_string(num[0]) + " " + to_string(num[1]);
            string s2 = to_string(num[0]) + " " + to_string(num[3]);
            string s3 = to_string(num[2]) + " " + to_string(num[1]);
            string s4 = to_string(num[2]) + " " + to_string(num[3]);
            if (st.count(s1))
            {
                st.erase(s1);
            }
            else
            {
                st.insert(s1);
            }
            if (st.count(s2))
            {
                st.erase(s2);
            }
            else
            {
                st.insert(s2);
            }
            if (st.count(s3))
            {
                st.erase(s3);
            }
            else
            {
                st.insert(s3);
            }
            if (st.count(s4))
            {
                st.erase(s4);
            }
            else
            {
                st.insert(s4);
            }
        }
        string s1 = to_string(x1) + " " + to_string(y1);
        string s2 = to_string(x1) + " " + to_string(y2);
        string s3 = to_string(x2) + " " + to_string(y1);
        string s4 = to_string(x2) + " " + to_string(y2);
        if (!st.count(s1) || !st.count(s2) || !st.count(s3) || !st.count(s4) || st.size() != 4)
        {
            return false;
        }
        return (area == 1LL * (x2 - x1) * (y2 - y1));
    }
};