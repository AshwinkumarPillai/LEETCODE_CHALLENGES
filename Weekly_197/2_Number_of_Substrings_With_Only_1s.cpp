class Solution
{
public:
    int numSub(string s)
    {
        long long ans = 0;
        int mp = 1000000007;
        int n = s.length();
        long long count = 0, i = 0;
        while (i < n && s[i] == '0')
            i++;
        if (i == n)
            return 0;
        for (; i < n; i++)
        {
            if (s[i] == '1')
                count++;
            else
            {
                ans = (ans % mp + ((count * (count + 1)) / 2) % mp) % mp;
                count = 0;
            }
        }
        if (count > 0)
            ans = (ans % mp + ((count * (count + 1)) / 2) % mp) % mp;
        return ans;
    }
};