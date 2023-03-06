class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        vector<bool>    res;
        int m = l.size();
        int i = -1;
        while (++i < m)
        {
            vector<int> temp = vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
            if (temp.size() == 2)
            {
                res.push_back(true);
                continue ;
            }
            sort(temp.begin(), temp.end());
            int diff = temp[1] - temp[0], j = 1, found = 0;
            cout << i << endl;
            while (++j < temp.size())
            {
                if (temp[j] - temp[j - 1] != diff)
                {
                    found = 1;
                    break ;
                }
            }
            if (!found)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res ;

    }
};
