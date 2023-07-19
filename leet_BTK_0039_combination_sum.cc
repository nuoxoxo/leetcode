class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> arr;
        backtrack( res, candidates, arr, 0, target );
        return res ;
    }

    void    backtrack(
        vector<vector<int>>& res,
        vector<int>& candidates,
        vector<int>& arr, int curr, int remain
    )
    {
        if ( !remain ) 
            res.push_back(arr);
        if ( remain < 0 )
            return ;
        int i = curr - 1;
        while (++i < (int) candidates.size())
        {
            arr.push_back(candidates[i]);
            backtrack( res, candidates, arr, i, remain - candidates[i] );
            arr.pop_back();
        }

    }
};
