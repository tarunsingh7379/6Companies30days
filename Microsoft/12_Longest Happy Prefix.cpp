// https://leetcode.com/problems/longest-happy-prefix/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

ll prefix_hash[100005];
ll powerr[100005];

class Solution
{
public:
    ll power(ll base, ll n, ll m)
    {
        ll ans = 1;
        while (n != 0)
        {
            if (n % 2 == 1)
            {
                n = n - 1;
                ans = (ans * base) % m;
            }
            else
            {
                n = n / 2;
                base = (base * base) % m;
            }
        }
        return ans;
    }

    ll compute_substring_hash(ll l, ll r)
    {
        ll hash = prefix_hash[r];

        if (l > 0)
        {
            hash = (hash - prefix_hash[l - 1] + M) % M;
        }

        // divide

        hash = (hash * power(power(31, l, M), M - 2, M)) % M;

        return hash;
    }

    // void precompute(int n)
    // {
    //     for (ll i = 0; i < n; i++)
    //     {
    //         powerr[i] = power(power(31, i, M), M - 2, M);
    //     }
    // }

    string longestPrefix(string s)
    {

        ll pr = 1;
        ll hash = 0;
        int n = s.size();
        for (ll i = 0; i < n; i++)
        {
            hash = (hash + ((s[i] - 'a' + 1) * pr) % M) % M;
            prefix_hash[i] = hash;
            pr = (pr * 31) % M;
        }

        // precompute(n);

        int ind = -1;
        for (int i = 0; i < n - 1; i++)
        {
            ll prefix = compute_substring_hash(0, i);
            ll suffix = compute_substring_hash(n - 1 - i, n - 1);
            if (prefix == suffix)
            {
                ind = i;
            }
        }

        string ans = "";
        if (ind != -1)
        {
            ans = s.substr(0, ind + 1);
        }
        return ans;
    }
};