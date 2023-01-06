// https://leetcode.com/problems/max-points-on-a-line/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

// map will store all slopes starting from i and ending at i+1,i+2,....,n-1
// it will store slope as {{dx,dy},i};
// dx can be negative

// also count parallel and perpendicular

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        map<pair<pair<int, int>, int>, int> mp;
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int perpendicular = 0, parallel = 0;
            for (int j = i + 1; j < n; j++)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                if ((dx > 0 && dy < 0) || (dx < 0 && dy < 0))
                {
                    dy = -dy;
                    dx = -dx;
                }
                mp[{{dx, dy}, i}]++;
                if (dy == 0)
                {
                    parallel++;
                }
                if (dx == 0)
                {
                    perpendicular++;
                }
            }
            ans = max(ans, parallel);
            ans = max(ans, perpendicular);
        }
        for (auto num : mp)
        {
            ans = max(ans, num.second);
        }
        return ans + 1;
    }
};