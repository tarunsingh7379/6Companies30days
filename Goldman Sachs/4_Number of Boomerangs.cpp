// https://leetcode.com/problems/number-of-boomerangs/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

// for each i, we will iterate over all j and compute distance between them
// and store it in map
// (i,j,k)
// for each i, we have to find two points such that they are at a same distance from i
// we will iterate over map, and for each distance, we have a frequency of each distance
// we will just pick two elements from same frequency in our answer
// and we can arrange it in our answer as well in two ways
// (i,j,k) or (i,k,j)
// ans will be nC2 and for arranging 2 ways
// therefore ans will be n*(n-1) where n is same distance frequency for a particular i;

class Solution
{
public:
    double dis(int x1, int y1, int x2, int y2)
    {
        double x = (x1 - x2) * (x1 - x2);
        double y = (y1 - y2) * (y1 - y2);
        double ans = sqrt(x + y);
        return ans;
    }

    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0, n = points.size();
        for (int i = 0; i < n; i++)
        {
            map<double, int> mp;
            for (int j = 0; j < n; j++)
            {
                double x = dis(points[i][0], points[i][1], points[j][0], points[j][1]);
                mp[x]++;
            }
            for (auto num : mp)
            {
                ans += (num.second * (num.second - 1));
            }
        }
        return ans;
    }
};