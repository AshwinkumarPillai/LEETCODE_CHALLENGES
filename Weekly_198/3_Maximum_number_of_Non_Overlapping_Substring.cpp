class Solution
{
public:
    int getRight(string &s, vector<pair<int, int>> &index, int i)
    {
        int right = index[s[i] - 'a'].second;
        for (int j = i; j < right; j++)
        {
            if (index[s[j] - 'a'].first < i)
                return -1;
            right = max(right, index[s[j] - 'a'].second);
        }
        return right;
    }

    vector<string> maxNumOfSubstrings(string s)
    {
        vector<pair<int, int>> index(26, {INT_MAX, -1});
        for (int i = 0; i < s.length(); i++)
        {
            int x = s[i] - 'a';
            index[x].first = min(index[x].first, i);
            index[x].second = max(index[x].second, i);
        }

        int end = INT_MAX;
        vector<string> ans(1);
        for (int i = 0; i < s.length(); i++)
        {
            if (i == index[s[i] - 'a'].first)
            {
                int r = getRight(s, index, i);
                if (r != -1)
                {
                    if (i > end)
                        ans.push_back("");
                    end = r;
                    ans.back() = s.substr(i, end - i + 1);
                }
            }
        }
        return ans;
    }
};