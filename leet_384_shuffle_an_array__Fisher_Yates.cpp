class Solution {

private:
    vector<int> original;

public:
    Solution(vector<int>& nums)
    {
        original = nums;
    }
    
    vector<int> reset()
    {
        return original;
    }
    
    vector<int> shuffle()
    {
        vector<int> result(original);
        int     i = original.size() ;
        while (-- i > -1)
        {
            int f = rand() % (i + 1);
            swap(result[i], result[f]);
        }
        return result ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
