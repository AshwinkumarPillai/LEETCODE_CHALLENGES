// sqrt(n) solution
class Solution
{
public:
    int kthFactor(int n, int k)
    {
        int d = 1;
        for (; d * d <= n; d++)
            if (n % d == 0 && --k == 0)
                return d;
        d--;
        if (d * d == n)
            d--;
        for (d = d - 1; d >= 1; d--)
        {
            if (n % d == 0 && --k == 0)
                return n / d;
        }
        return -1;
    }
};

// O(n) solution
class Solution
{
public:
    int kthFactor(int n, int k)
    {
        if (n == 1)
        {
            if (k > 1)
                return -1;
            return 1;
        }
        vector<int> f;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                f.emplace_back(i);
        }
        if (k > f.size())
            return -1;
        return f[k - 1];
    }
};