// https://leetcode.com/problems/airplane-seat-assignment-probability/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        double ans = 1.0;
        if (n > 1)
        {
            ans = 0.5;
        }
        return ans;
    }
};