class RLEIterator {
public:
    vector<int> core;
    int         i = 0; // current index
    int         len;

    RLEIterator(vector<int>& encoding)
    {
        core = encoding;
        len = (int) core.size();
    }
    
    int next(int n)
    {
        while (i < len - 1)
        {
            if (n > core[i])
            {
                n -= core[i];
                i += 2;
            }
            else
            {
                core[i] -= n;
                return (core[i + 1]);
            }
        }
        return (-1);
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
