class BrowserHistory
{
public:
    int i = 0;
    vector<string> bh;
    BrowserHistory(string h)
    {
        bh.emplace_back(h);
    }

    void visit(string url)
    {
        int n = bh.size() - 1;
        if (i == n)
        {
            bh.emplace_back(url);
        }
        else
        {
            bh.resize(i + 1);
            bh.emplace_back(url);
        }
        i = (int)bh.size() - 1;
    }

    string back(int steps)
    {
        if (i - steps < 0)
        {
            i = 0;
            return bh[i];
        }
        i -= steps;
        return bh[i];
    }

    string forward(int steps)
    {
        int n = bh.size();
        if (i + steps >= n)
        {
            i = n - 1;
            return bh[i];
        }
        i += steps;
        return bh[i];
    }
};