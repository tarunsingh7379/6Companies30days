// https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>
typedef long long int ll;
#define M 1000000007
using namespace std;

// Just check whether there is a cycle or not.
// If there is no cycle we can finish all the course otherwise we can't.

class Solution
{
public:
    bool dfs(int node, vector<int> &pathvis, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, pathvis, vis, adj))
                {
                    return true;
                }
            }
            else if (pathvis[it])
            {
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto num : prerequisites)
        {
            adj[num[1]].push_back(num[0]);
        }
        vector<int> vis(numCourses, 0), pathvis(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, pathvis, vis, adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};