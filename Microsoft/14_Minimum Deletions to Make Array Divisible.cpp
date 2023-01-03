// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int g = 0;
        for (auto num : numsDivide)
        {
            g = __gcd(g, num);
        }
        int ans = 0;
        map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }
        int flag = 0;
        for (auto num : mp)
        {
            int x = num.first;
            int cnt = num.second;
            if (g % x == 0)
            {
                flag = 1;
                break;
            }
            ans += cnt;
        }
        if (flag == 0)
        {
            ans = -1;
        }
        return ans;
    }
};