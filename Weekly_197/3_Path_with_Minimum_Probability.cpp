// Dijkistra's with a minor tweak

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        unordered_map<int, vector<pair<int, double>>> m;
        int sz = edges.size();
        for (int i = 0; i < sz; i++)
        {
            m[edges[i][0]].push_back({edges[i][1], succProb[i]});
            m[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<int> vis(n);
        vector<double> dist(n, 0);
        dist[start] = 1;
        priority_queue<pair<double, int>> q;
        q.push({1, start});
        while (!q.empty())
        {
            auto p = q.top();
            q.pop();
            if (vis[p.second])
                continue;
            vis[p.second] = 1;
            for (auto x : m[p.second])
            {
                if (!vis[x.first])
                {
                    if (dist[x.first] < x.second * p.first)
                    {
                        dist[x.first] = x.second * p.first;
                        q.push({dist[x.first], x.first});
                    }
                }
            }
        }
        return dist[end];
    }
};