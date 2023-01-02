// https://leetcode.com/problems/most-profitable-path-in-a-tree/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

class Solution
{
public:
    void dfsBob(int node, int bob, vector<int> &ans, vector<int> &path, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        path.push_back(node);
        if (node == bob)
        {
            ans = path;
        }
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfsBob(it, bob, ans, path, vis, adj);
            }
        }
        path.pop_back();
    }

    void dfsAlice(int node, int time, int &ans, int sum, vector<int> &vis, vector<int> &visBobTime, vector<vector<int>> &adj, vector<int> &cost)
    {
        vis[node] = 1;
        int extra = 0;
        if (visBobTime[node] == -1)
        {
            extra = cost[node];
        }
        else if (visBobTime[node] == time)
        {
            extra = cost[node] / 2;
        }
        else if (visBobTime[node] < time)
        {
        }
        else
        {
            extra = cost[node];
        }
        sum += extra;
        int cnt = 0;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfsAlice(it, time + 1, ans, sum, vis, visBobTime, adj, cost);
                cnt++;
            }
        }
        if (cnt == 0)
        {
            ans = max(ans, sum);
        }
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto num : edges)
        {
            adj[num[0]].push_back(num[1]);
            adj[num[1]].push_back(num[0]);
        }
        vector<int> visBob(n, 0);
        vector<int> bobPath, path;
        dfsBob(0, bob, bobPath, path, visBob, adj);
        reverse(bobPath.begin(), bobPath.end());
        vector<int> visBobTime(n, -1);
        for (int i = 0; i < bobPath.size(); i++)
        {
            visBobTime[bobPath[i]] = i;
        }
        int ans = INT_MIN, sum = 0;
        vector<int> visAlice(n, 0);
        dfsAlice(0, 0, ans, sum, visAlice, visBobTime, adj, amount);
        return ans;
    }
};
