// https://leetcode.com/problems/number-of-people-aware-of-a-secret/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        map<ll, ll> mp;
        mp[1] = 1;
        for (ll i = 2; i <= n; i++)
        {
            ll active = 0;
            vector<int> v;
            for (auto num : mp)
            {
                int d = i - num.first;
                if (d == forget)
                {
                    v.push_back(num.first);
                    continue;
                }
                if (d >= delay)
                {
                    active = (active + num.second) % M;
                }
            }
            mp[i] = active;
            for (auto num : v)
            {
                mp.erase(num);
            }
        }
        ll ans = 0;
        for (auto num : mp)
        {
            ans = (ans + num.second) % M;
        }
        return ans;
    }
};