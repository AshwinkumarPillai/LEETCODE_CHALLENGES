

// My solution - in a hurry
class Solution
{
public:
    static int cd(pair<int, int> &p)
    {
        return ((p.second - p.first) + 1);
    }
    static bool compare(pair<int, int> &a, pair<int, int> &b)
    {
        int d1 = cd(a);
        int d2 = cd(b);
        if (d1 == d2)
        {
            return a.first < b.first;
        }
        return d1 < d2;
    }
    int minSumOfLengths(vector<int> &arr, int t)
    {
        int i = 0, j = 0;
        int n = arr.size();
        int csum = 0;
        vector<pair<int, int>> ans;
        while (i < n && j < n)
        {
            csum += arr[j];
            if (csum == t)
            {
                ans.push_back({i, j});
                j++;
                csum -= arr[i++];
            }
            else if (csum < t)
            {
                j++;
            }
            else
            {
                csum -= arr[i++];
                csum -= arr[j];
            }
        }
        int m = ans.size();
        if (m == 0 || m == 1)
        {
            return -1;
        }
        else if (m == 2)
        {
            int val = cd(ans[0]) + cd(ans[1]);
            if (n == 3)
            {
                return (val == 2) ? 2 : -1;
            }
            return val;
        }
        sort(ans.begin(), ans.end(), compare);
        int min1 = cd(ans[0]);
        int min2;
        int ai = ans[0].first;
        int aj = ans[0].second;
        int k = 1;
        while (k < n)
        {
            int ci = ans[k].first, cj = ans[k].second;
            if (ci > aj || cj < ai)
            {
                min2 = cd(ans[k]);
                break;
            }
            k++;
        }
        return min1 + min2;
    }
};