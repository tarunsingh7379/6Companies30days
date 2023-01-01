// https://leetcode.com/problems/largest-divisible-subset/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n);
        vector<int> par(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            par[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        par[i] = j;
                    }
                }
            }
        }
        int ma = 0, pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > ma)
            {
                ma = dp[i];
                pos = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[pos]);
        while (par[pos] != pos)
        {
            pos = par[pos];
            ans.push_back(nums[pos]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};