class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &c)
    {
        set<int> s;
        s.insert(0);
        int count = 0;
        for (auto x : c)
        {
            if (x[1] == 0 || s.find(x[1]) != s.end())
            {
                s.insert(x[0]);
            }
            if (x[0] == 0)
            {
                count++;
                s.insert(x[1]);
            }
        }

        for (auto x : c)
        {
            if ((s.find(x[0]) != s.end()) && (s.find(x[1]) == s.end()))
            {
                s.insert(x[1]);
                count++;
            }
            else if (s.find(x[1]) != s.end() && s.find(x[0]) == s.end())
            {
                s.insert(x[0]);
            }
        }

        return count;
    }
};