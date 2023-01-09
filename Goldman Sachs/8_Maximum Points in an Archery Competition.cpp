// https://leetcode.com/problems/maximum-points-in-an-archery-competition/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
    {
        int n = 12;
        vector<int> ans(n, 0);
        int ma = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            int got = 0, haveArrows = numArrows;
            vector<int> temp(12, 0);
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    got += j;
                    haveArrows -= (aliceArrows[j] + 1);
                    temp[j] = aliceArrows[j] + 1;
                    if (haveArrows < 0)
                    {
                        break;
                    }
                }
            }
            if (haveArrows < 0)
            {
                continue;
            }
            temp[0] += haveArrows;
            if (got > ma)
            {
                ma = got;
                ans = temp;
            }
        }
        return ans;
    }
};