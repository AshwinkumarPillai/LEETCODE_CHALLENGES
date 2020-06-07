class Solution
{
public:
    int dp[101][21][101];
    int paintMe(vector<int> &h, vector<vector<int>> &cost, int i, int prevc, int g, int t, int lim, int n)
    {
        if (g > t)
        {
            return INT_MAX / 2;
        }
        if (i == lim)
        {
            return (g == t) ? 0 : INT_MAX / 2;
        }
        if (dp[i][prevc][g] != -1)
        {
            return dp[i][prevc][g];
        }
        int ans = INT_MAX;
        if (h[i] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                int val = (j + 1 != prevc) ? g + 1 : g;
                ans = min(ans, cost[i][j] + paintMe(h, cost, i + 1, j + 1, val, t, lim, n));
            }
        }
        else
        {
            int val = (h[i] != prevc) ? g + 1 : g;
            ans = paintMe(h, cost, i + 1, h[i], val, t, lim, n);
        }
        return dp[i][prevc][g] = ans;
    }

    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        memset(dp, -1, sizeof(dp));
        int ans = paintMe(houses, cost, 0, 0, 0, target, m, n);
        return (ans >= INT_MAX / 2) ? -1 : ans;
    }
};
