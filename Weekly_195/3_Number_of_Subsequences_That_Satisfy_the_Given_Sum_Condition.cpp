class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0, m = 1000000007;
        vector<int> p = {0, 1}; // Powers of 2
        for (int i = 2; i <= n; i++)
            p.emplace_back((p.back() << 1) % m); // store powers of 2 mod m
        int i = 0, j = n - 1;
        for (; i <= j; i++)
        {
            while (i <= j && nums[i] + nums[j] > target) // decrement j till the sum is large
                j--;
            ans = (ans + p[j - i + 1]) % m; // each time add 2^(j-1) => 2^(size of the array we obtained)
        }
        return ans;
    }
};