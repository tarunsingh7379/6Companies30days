// https://leetcode.com/problems/bulls-and-cows/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0, cows = 0;
        int n = secret.size();
        map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                mp[secret[i]]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (secret[i] != guess[i])
            {
                if (mp[guess[i]])
                {
                    cows++;
                    mp[guess[i]]--;
                }
            }
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};