class TreeAncestor
{
public:
    vector<vector<int>> dp;
    TreeAncestor(int m, vector<int> &p)
    {
        int n = p.size();
        dp.resize(20, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = p[i];
        }
        for (int i = 1; i < 20; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int parent = dp[i - 1][j];
                if (parent != -1)
                    dp[i][j] = dp[i - 1][parent];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < 20; i++)
        {
            if (k & (1 << i))
            {
                node = dp[i][node];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};
