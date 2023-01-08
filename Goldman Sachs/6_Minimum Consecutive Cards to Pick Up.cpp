// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        int ans = INT_MAX;
        map<int, int> mp;
        int n = cards.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.find(cards[i]) != mp.end())
            {
                ans = min(ans, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;
        }
        if (ans == INT_MAX)
        {
            ans = -1;
        }
        return ans;
    }
};