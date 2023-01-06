// https://leetcode.com/problems/factorial-trailing-zeroes/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        for (int i = 5; i <= n; i *= 5)
        {
            ans += n / i;
        }
        return ans;
    }
};