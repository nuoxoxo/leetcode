class NumArray {
public:
    vector<int> arr;
    int         len;

    NumArray(vector<int>& nums) {
        len = nums.size();
        arr = nums ;
    }
    
    int sumRange(int left, int right) {
        if (left > len - 1) return 0;
        int i = left - 1;
        int res = 0;
        while (++i < len && i < right + 1)
            res += arr[i];
        return res ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
