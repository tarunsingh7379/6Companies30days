// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

// nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
// nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff;
// nums1[i] - nums2[i] - diff <= nums1[j] - nums2[j]

// We just need to count for a particular j how many i's are there
// such that they satisfy above equation

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {
        long long ans = 0;
        ordered_set st;
        map<int, int> mp;
        int n = nums1.size();
        for (int j = 0; j < n; j++)
        {
            int z = mp[nums1[j] - nums2[j]] + 1;
            long long x = st.order_of_key({nums1[j] - nums2[j], z});
            ans += x;
            int val = nums1[j] - nums2[j] - diff;
            int cnt = mp[val];
            cnt++;
            st.insert({val, cnt});
            mp[val] = cnt;
        }
        return ans;
    }
};
