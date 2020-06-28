// Weak TestCases
class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        long long ans = 0;
        for (int x : arr)
            ans += x;
        return (ans % k == 0);
    }
};