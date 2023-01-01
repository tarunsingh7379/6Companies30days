// https://leetcode.com/problems/combination-sum-iii/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> v;
        for (int i = 1; i <= 9; i++)
        {
            v.push_back(i);
        }
        for (int i = 0; i < (1 << 9); i++)
        {
            int sum = 0, cnt = 0;
            vector<int> temp;
            for (int j = 0; j < 9; j++)
            {
                if (i & (1 << j))
                {
                    sum += v[j];
                    cnt++;
                    temp.push_back(v[j]);
                }
            }
            if (cnt == k && sum == n)
            {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
