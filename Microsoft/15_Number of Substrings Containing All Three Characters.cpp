// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

// for a particular l ---> r substring, if it contains a, b, and c,
// then all the substrings ending at r, r+1, r+2, ....., n-1 will also contain atleast
// one a, b and c.
// Therefore these substrings will be included in our answer.

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int ans = 0;
        unordered_map<char, int> mp;
        int l = 0, n = s.size();
        for (int r = 0; r < n; r++)
        {
            mp[s[r]]++;
            while (mp.size() == 3 && l < r)
            {
                ans += (n - r);
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
        }
        return ans;
    }
};