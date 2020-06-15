class Solution
{
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }

    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        map<int, int> m;
        for (int x : arr)
        {
            m[x]++;
        }
        vector<pair<int, int>> freq;
        for (auto p : m)
        {
            freq.push_back({p.first, p.second});
        }
        sort(freq.begin(), freq.end(), compare);

        while (k--)
        {
            int n = freq.size();
            if (n == 0)
            {
                return 0;
            }
            auto p = freq.back();
            if (p.second > 1)
            {
                freq[n - 1].second--;
            }
            else
            {
                freq.pop_back();
            }
        }
        return freq.size();
    }
};