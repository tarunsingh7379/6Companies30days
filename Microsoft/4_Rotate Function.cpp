// https://leetcode.com/problems/rotate-function/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + i * nums[i];
        }
        ans = max(ans, sum);
        for (int i = n - 1; i > 0; i--)
        {
            sum -= (n - 1) * nums[i];
            sum += prefix[i - 1];
            sum += prefix[n - 1] - prefix[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};