class Solution
{
public:
    static bool compare(int i, int j)
    {
        return i > j;
    }

    int maxProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), compare);
        return (nums[0] - 1) * (nums[1] - 1);
    }
};