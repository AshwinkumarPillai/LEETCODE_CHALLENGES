class Solution
{
public:
    vector<string> getFolderNames(vector<string> &names)
    {
        unordered_map<string, int> m;
        vector<string> ans;
        for (string x : names)
        {
            if (m.find(x) == m.end())
            {
                m[x]++;
                ans.push_back(x);
            }
            else
            {
                int v = m[x];
                m[x]++;
                string s = x;
                s = x + "(" + to_string(v) + ")";
                while (m.find(s) != m.end())
                {
                    s = x + "(" + to_string(++v) + ")";
                }
                m[s]++;
                ans.push_back(s);
            }
        }
        return ans;
    }
};