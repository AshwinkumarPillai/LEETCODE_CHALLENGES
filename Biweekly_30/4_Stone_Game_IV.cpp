class Solution
{
public:
    bool ips(double x)
    {
        double sq = sqrt(x);
        return ((sq - floor(sq)) == 0);
    }
    vector<int> dp;
    int cp(int n)
    {
        if (n <= 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        for (int i = 1; i * i <= n; i++)
        {
            if (!cp(n - i * i))
                return dp[n] = 1;
        }
        return dp[n] = 0;
    }

    bool winnerSquareGame(int n)
    {
        if (ips(n))
            return true;
        dp.resize(n + 1, -1);
        return cp(n);
    }
};