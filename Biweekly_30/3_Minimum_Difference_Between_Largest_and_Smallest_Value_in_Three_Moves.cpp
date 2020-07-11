class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (nums.size() < 5)
            return 0;
        sort(nums.begin(), nums.end());
        int d1 = nums[n - 4] - nums[0];
        int d2 = nums[n - 3] - nums[1];
        int d3 = nums[n - 2] - nums[2];
        int d4 = nums[n - 1] - nums[3];
        return min({d1, d2, d3, d4});
    }
};