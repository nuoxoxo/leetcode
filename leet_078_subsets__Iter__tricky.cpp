class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int                 s, subs, i, j;
        vector<vector<int>> E;

        E.push_back({});
        s = nums.size();
        i = -1;
        while (++i < s)
        {
            subs = E.size();
            j = -1;
            while (++j < subs)
            {
                // cout << i << ".1: ";
                E.push_back(E[j]);
                // pa(E);
                E.back().push_back(nums[i]);
                // cout << i << ".2: ";
                // pa(E);
            }
        }
        return E ;
    }
    
    // void pa(vector<vector<int>> E)
    // {
    //     int i, j;
    //     i = -1;
    //     while (++i < E.size())
    //     {
    //         j = -1;
    //         cout << "[ ";
    //         while (++j < E[i].size())
    //         {
    //             cout << E[i][j] << ' ';
    //         }
    //         cout << "]";
    //     }
    //     cout << endl;
    // }
};
