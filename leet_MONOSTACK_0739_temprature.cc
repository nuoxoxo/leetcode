class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp /*temperatures*/)
    {
        vector<int> res((int) temp.size(), 0);
        stack<int>  hot;
        int i = (int)temp.size();
        
        while (--i > -1)
        {
            while (!hot.empty() && (temp[i] >= temp[hot.top()]))
                hot.pop();
            if (!hot.empty())
                res[i] = hot.top() - i;
            hot.push(i);
        }
        return (res);
        /*
        vector<int> res;
        int len = (int) temp.size();
        int i = -1, j;
        while (++i < len - 1)
        {
            j = i;
            while (++j < len)
            {
                if (temp[i] < temp[j])
                {
                    res.push_back(j - i);
                    break ;
                }
            }
            if ((int)res.size() ^ i + 1)
                res.push_back(0);
        }
        res.push_back(0);
        return res;
        */
    }
};
