// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

// Sort it and find the first and last position
// that are not matched with the sorted version of the array
// then answer is just (ma - mi + 1)

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int n = nums.size();
        int mi = n, ma = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != v[i])
            {
                mi = min(mi, i);
                ma = max(ma, i);
            }
        }
        if (mi == n)
        {
            return 0;
        }
        return (ma - mi + 1);
    }
};