// https://leetcode.com/problems/count-good-triplets-in-an-array/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
        {
            pos[nums2[i]] = i;
        }

        vector<int> left(n);
        ordered_set st1;
        for (int i = 0; i < n; i++)
        {
            left[i] = st1.order_of_key(pos[nums1[i]]);
            st1.insert(pos[nums1[i]]);
        }

        vector<int> right(n);
        ordered_set st2;
        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = st2.order_of_key(-pos[nums1[i]]);
            st2.insert(-pos[nums1[i]]);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans + 1LL * left[i] * right[i];
        }
        return ans;
    }
};
