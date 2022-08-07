class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        /// wrong way to cal `mid`
        // pair<vector<int>::iterator, vector<int>::iterator>  p;
        // p = std::minmax_element(nums.begin(), nums.end());
        // int mid = (*p.second - *p.first) / 2 + *p.first;

        /// also wrong 
        //int mid = std::accumulate(nums.begin(), nums.end(), 0) / nums.size();
        
        sort(nums.begin(), nums.end());
        int mid_index = (int) nums.size() / 2;
        int mid = nums[mid_index];
        int res = 0;
        for (int n: nums)
        {
            res += abs(n - mid);
        }
        return res;
    }
};

/* 
[1,0,0,8,6]
*/
