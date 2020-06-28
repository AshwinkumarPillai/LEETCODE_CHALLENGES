// DP Solution
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int D = 0;
        int N = nums[0] == 1 ? 1 : 0;

        int res = INT_MIN;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                D = N;
                N = 0;
            }
            else
            {
                D = max(D + 1, N);
                N = N + 1;
            }

            res = max(res, D);
        }

        return res == INT_MIN ? 0 : res;
    }
};

// Elegant solution
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxg = INT_MIN;
        int cnt = 0;
        int pre = 0;
        int suc = 0;
        int flag = 1;
        for (int i : nums)
        {
            if (i == 0)
            {
                maxg = max(maxg, pre + suc);
                pre = suc;
                suc = 0;
                flag = 0;
            }
            else
            {
                suc++;
            }
        }
        if (flag == 0)
            maxg = max(maxg, pre + suc);
        else
            return pre + suc - 1;
        return maxg;
    }
};

// My Solution
class Solution
{
public:
    int getLength(int i, vector<int> &nums)
    {
        int l = i - 1;
        int r = i + 1;
        int n = nums.size();
        while (l - 1 >= 0 && nums[l - 1] == 1)
            l--;
        while (r + 1 < n && nums[r + 1] == 1)
            r++;
        return ((i - l) + (r - i));
    }

    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ones = 0;
        int zeros = 0;
        for (int x : nums)
        {
            if (x == 0)
                zeros++;
            else
                ones++;
        }

        if (ones == 0)
            return 0;
        if (ones == 1)
        {
            if (n == 1)
                return 0;
            return 1;
        }
        if (zeros == 0 || zeros == 1)
            return n - 1;
        set<int> s;
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] == 0 && nums[i - 1] == 1 && nums[i + 1] == 1)
                s.insert(i);
        }
        int maxlen = 1;
        int cmax = 1;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            maxlen = max(maxlen, count);
        }
        for (int x : s)
        {
            int val = getLength(x, nums);
            cmax = max(cmax, val);
        }
        return max(maxlen, cmax);
    }
};