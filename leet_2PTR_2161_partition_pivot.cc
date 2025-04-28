class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        int N = nums.size();
        vector<int> res(N);
        int l = -1, L = 0, R = N - 1, r;
        while (++l < N)
        {
            r = N - l - 1;
            if (nums[l] < pivot)
                res[L++] = nums[l];
            if (nums[r] > pivot) 
                res[R--] = nums[r];
        }
        while (L <= R)
            res[L++] = pivot;
        return res;
    }
};
