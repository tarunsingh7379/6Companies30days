// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

// use dijkstra algorithm with dp to count number of ways to reach a particular node

// dp[node] -> number of ways to reach this node from node 0 with shortest path

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {

        vector<vector<pair<ll, ll>>> adj(n);
        for (auto num : roads)
        {
            adj[num[0]].push_back({num[1], num[2]});
            adj[num[1]].push_back({num[0], num[2]});
        }

        vector<ll> dis(n, 1e18);
        vector<ll> dp(n, 0);
        set<pair<ll, ll>> st;
        st.insert({0, 0});
        dis[0] = 0;
        dp[0] = 1;

        while (!st.empty())
        {
            auto it = st.begin();
            ll cost = it->first, node = it->second;
            st.erase(st.begin());
            for (auto num : adj[node])
            {
                ll u = num.first;
                ll w = num.second;
                if (cost + w < dis[u])
                {
                    dis[u] = cost + w;
                    st.insert({dis[u], u});
                    dp[u] = dp[node];
                }
                else if (cost + w == dis[u])
                {
                    dis[u] = cost + w;
                    st.insert({dis[u], u});
                    dp[u] = (dp[u] + dp[node]) % M;
                }
            }
        }
        return dp[n - 1];
    }
};