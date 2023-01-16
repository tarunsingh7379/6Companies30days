// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    int func(int sum, int k, int mask, int x, int n, vector<int> &a, vector<int> &dp)
    {
        if (k == 0)
        {
            return 1;
        }
        if (dp[mask] != -1)
        {
            return dp[mask];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!(mask & (1 << i)))
            {
                if (sum > a[i])
                {
                    ans = ans | func(sum - a[i], k, mask | (1 << i), x, n, a, dp);
                }
                else if (sum == a[i])
                {
                    ans = ans | func(x, k - 1, mask | (1 << i), x, n, a, dp);
                }
            }
        }
        return dp[mask] = ans;
    }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0, n = nums.size();
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum % k != 0)
        {
            return false;
        }
        int x = sum / k;
        vector<int> dp((1 << n), -1);
        return func(x, k, 0, x, n, nums, dp);
    }
};