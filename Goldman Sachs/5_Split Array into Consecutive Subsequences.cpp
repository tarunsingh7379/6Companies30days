// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }
        int cnt = nums.size();
        for (auto num : nums)
        {
            if (mp[num] && mp[num + 1] && mp[num + 2])
            {
                mp[num]--;
                mp[num + 1]--;
                mp[num + 2]--;
                cnt -= 3;
                num += 3;
                while (mp[num] && mp[num] > mp[num - 1])
                {
                    mp[num]--;
                    num++;
                    cnt--;
                }
            }
        }
        return cnt == 0;
    }
};