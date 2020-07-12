class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        long long ans = 0;
        unordered_map<int, int> m;
        for (int x : nums)
            m[x]++;
        for (auto p : m)
        {
            if (p.second > 1)
                ans += (p.second * (p.second - 1)) / 2;
        }
        return ans;
    }
};