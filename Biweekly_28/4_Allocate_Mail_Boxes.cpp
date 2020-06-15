class Solution
{
public:
    int calcDist(vector<int> &h, vector<vector<int>> &costs, vector<vector<int>> &dp, int k, int i)
    {
        int n = h.size();
        if (k == 0 && i == n)
            return 0;
        if (k == 0 || i == n)
            return INT_MAX / 100;
        if (dp[k][i] != -1)
            return dp[k][i];
        int ans = INT_MAX / 100;
        for (int j = i; j < n; j++)
        {
            ans = min(ans, costs[i][j] + calcDist(h, costs, dp, k - 1, j + 1));
        }
        return dp[k][i] = ans;
    }

    int minDistance(vector<int> &h, int k)
    {
        int n = h.size();
        sort(h.begin(), h.end());
        vector<vector<int>> costs(101, vector<int>(101));
        vector<vector<int>> dp(101, vector<int>(101, -1));

        //Precalculate cost
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int m = i; m <= j; m++)
                {
                    costs[i][j] += abs(h[(i + j) / 2] - h[m]);
                }
            }
        }
        return calcDist(h, costs, dp, k, 0);
    }
};