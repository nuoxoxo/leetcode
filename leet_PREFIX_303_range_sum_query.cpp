class NumArray {
public:
    vector<long>    prefixsum ;
    int             len = 0;

    NumArray(vector<int>& nums) {
        int i = 0;

        prefixsum.push_back(nums[i]);
        len = nums.size() ;
        while (++i < len)
        {
            prefixsum.push_back(nums[i]);
            prefixsum[i] += prefixsum[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left > len - 1) return 0;

        int     R = right < len - 1 ? right : len - 1;
        long    res = prefixsum[R];

        if (!left)  return res ;
        return ( res -= prefixsum[left - 1] ) ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
