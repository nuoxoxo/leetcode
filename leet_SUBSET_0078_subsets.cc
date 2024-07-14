class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<vector<int>>(*)(vector<int> &)> solutions {
            bruteforce,
            // backtrack,
        };
        return solutions[0](nums);

    static vector<vector<int>> backtrack(vector<int>& nums)
    {
        int N = nums.size();
        vector<vector<int>> res;

        std::function<void(int, vector<int>)> Backtrack = [&](int i, vector<int> curr)
        {
            if (i == N)
            {
                res.push_back(curr);
                return ;
            }
            Backtrack(i + 1, curr);
            curr.push_back(nums[i]);
            Backtrack(i + 1, curr);
            curr.pop_back();
        };
        Backtrack(0, vector<int>{});
        return res;
    }


    static vector<vector<int>> bruteforce(vector<int>& nums)
    {
        int i = -1;
        vector<vector<int>> res;
        res.push_back( vector<int>{} );
        // vector<vector<int>> res = {{}};
        for (int n: nums)
        {
            int S = res.size();
            int j = -1;
            while (++j < S)
            {
                res.push_back(res[j]);
                res.back().push_back(n);
            }
        }
        return res;
    }
};
