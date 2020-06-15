class Solution
{
public:
    bool isvalid(vector<int> &bd, int mid, int m, int k)
    {
        int b = 0, c = 0; // b - bouque , c - num of consequetive flowers.
        int n = bd.size();
        for (int i = 0; i < n; i++)
        {
            if (bd[i] <= mid)
            {
                if (++c == k)
                {
                    b++;
                    c = 0;
                }
            }
            else
                c = 0;
        }
        return (b >= m);
    }

    int minDays(vector<int> &bd, int m, int k)
    {
        int low = 0, high = INT_MAX - 1, ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isvalid(bd, mid, m, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};