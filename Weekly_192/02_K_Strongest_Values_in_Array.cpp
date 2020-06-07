class Solution
{
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }

    vector<int> getStrongest(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k == n)
            return arr;
        vector<pair<int, int>> calc;
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int m = arr[(n - 1) / 2];
        for (int x : arr)
        {
            calc.push_back({abs(x - m), x});
        }
        sort(calc.begin(), calc.end(), compare);
        for (int i = 0; i < k; i++)
        {
            ans.emplace_back(calc[i].second);
        }
        return ans;
    }
};