class Solution
{
public:
    int maxArea(int h, int w, vector<int> &hc, vector<int> &vc)
    {
        int mod = 1000000007;
        int maxh = 0, maxv = 0;
        int ch = 0;
        int cv = 0;
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        hc.push_back(h);
        vc.push_back(w);
        for (int i = 0; i < (int)hc.size(); i++)
        {
            int diff = hc[i] - ch;
            maxh = max(diff, maxh);
            ch = hc[i];
        }
        for (int i = 0; i < (int)vc.size(); i++)
        {
            int diff = vc[i] - cv;
            maxv = max(diff, maxv);
            cv = vc[i];
        }
        long long result = (maxh % mod);
        result = result * (maxv % mod) % mod;
        return (result % mod);
    }
};