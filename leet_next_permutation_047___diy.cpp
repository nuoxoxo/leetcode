class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        next_perm(0, (int) nums.size(), nums, res);
        return res ;
    }

    void    next_perm(int L, int R, vector<int> n, vector<vector<int>>& v)
    {
        if (L != R - 1)
        {
            int i = L - 1;
            while (++i < R)
            {
                if (i == L || n[i] != n[L])
                {
                    swap(n[i], n[L]);
                    next_perm(L + 1, R, n, v);
                }
            }
        }
        else
            v.push_back(n);
    }
};
