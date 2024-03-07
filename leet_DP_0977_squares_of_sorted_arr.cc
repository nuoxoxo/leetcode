class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int N = (int)nums.size();
        int l = 0, r = N - 1;
        vector<int> res(N);
        while (l <= r) {
            --N;
            int L = abs(nums[l]), R = abs(nums[r]);
            if (L < R) {
                res[N] = R * R;
                r--;
            } else {
                res[N] = L * L;
                l++;
            }
        }
        return res;
    }
};
