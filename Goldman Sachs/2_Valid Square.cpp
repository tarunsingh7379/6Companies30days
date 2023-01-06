// https://leetcode.com/problems/valid-square/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

// There should be four unique points to form a square
// compute distance between every points, we will get 6 distances
// in which four will be the sides of square and 2 will be the diagonals
// all sides will be equal and two diagonals will also be equal.
// therfore for square, there should be two unique distances.

class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<pair<int, int>> v;
        v.push_back({p1[0], p1[1]});
        v.push_back({p2[0], p2[1]});
        v.push_back({p3[0], p3[1]});
        v.push_back({p4[0], p4[1]});
        set<pair<int, int>> st, st1(v.begin(), v.end());
        if (st1.size() != 4)
        {
            return false;
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                int d1 = abs(v[j].second - v[i].second);
                int d2 = abs(v[j].first - v[i].first);
                if (d1 > d2)
                {
                    swap(d1, d2);
                }
                st.insert({d1, d2});
            }
        }
        return st.size() == 2;
    }
};
