class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        vector<int> ans(n, -1);
        set<int> dry;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            if (rains[i] == 0)
            {
                ans[i] = 1;
                dry.insert(i);
            }
            else
            {
                int val = rains[i];
                if (m.find(val) != m.end())
                {
                    auto it = dry.lower_bound(m[val]);
                    if (it == dry.end())
                        return {};
                    int index = *it;
                    ans[index] = val;
                    dry.erase(index);
                }
                m[val] = i;
            }
        }
        return ans;
    }
};