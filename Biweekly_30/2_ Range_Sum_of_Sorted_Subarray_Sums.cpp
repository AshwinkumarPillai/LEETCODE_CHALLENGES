class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int l, int r)
    {
        int mp = 1000000007;
        vector<long long> ans;
        for (int i = 0; i < n; i++)
        {
            long long sum = nums[i];
            ans.push_back(sum);
            for (int j = i + 1; j < n; j++)
            {
                sum += nums[j];
                ans.push_back(sum);
            }
        }
        sort(ans.begin(), ans.end());
        l--;
        long long fans = 0;
        while (l < r)
        {
            fans = ((fans % mp) + (ans[l++] % mp)) % mp;
        }
        return fans;
    }
};