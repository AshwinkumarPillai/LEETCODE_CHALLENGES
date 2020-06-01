class Solution
{
public:
    int gcd(int i, int j)
    {
        if (i == 0)
        {
            return j;
        }
        return gcd(j % i, i);
    }
    vector<string> simplifiedFractions(int n)
    {
        vector<string> ans;
        if (n == 1)
        {
            return ans;
        }
        if (n == 2)
        {
            ans.emplace_back("1/2");
            return ans;
        }
        ans.emplace_back("1/2");
        for (int i = 3; i <= n; i++)
        {
            string s = "1/" + to_string(i);
            for (int j = 2; j < n; j++)
            {

                if (i < j)
                {
                    break;
                }
                int cm = gcd(i, j);
                if (cm > 1)
                {
                    continue;
                }
                string t = to_string(j) + "/" + to_string(i);
                ans.emplace_back(t);
            }
            ans.emplace_back(s);
        }
        return ans;
    }
};