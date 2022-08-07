class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n)
    {
        int s = (int) n.size();
        if (s < 3)
            return {};
        sort(n.begin(), n.end());
        vector<vector<int>> res;
        int                 i = -1;
        while (++i < s - 2)
        {
            if (!i || n[i] != n[i - 1])
            {
                int j = i + 1;
                int k = s - 1;
                while (j < k)
                {
                    int tmp = n[i] + n[j] + n[k];
                    if (tmp < 0)
                        ++j;
                    else if (tmp > 0)
                        --k;
                    else
                    {
                        res.push_back( { n[i], n[j], n[k] } );
                        while (j < k && n[j + 1] == n[j])
                            ++j;
                        while (j < k && n[k - 1] == n[k])
                            --k;
                        ++j;
                        --k;
                    }
                }
            }
        }
        return res ;
    }
};
