class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int>             temp;
        vector<int>::iterator   it;

        for (int n: nums)
        {
            it = std::lower_bound(temp.begin(), temp.end(), n);
            if (it == temp.end())
                temp.push_back(n);
            else
                *it = n;
        }
        return ((int) temp.size());
    }

    void    printer(vector<int> temp)
    {
        int     i = -1;
        while (++i < (int) temp.size())
            cout << temp[i] << ' ';
        cout << endl;
    }
};
