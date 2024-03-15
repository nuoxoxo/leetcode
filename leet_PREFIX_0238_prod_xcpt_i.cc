class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        #define vi vector<int>
        int N = (int) nums.size();
        vi L(N, 0), R(N, 0);
        vi res(N, 0);
        L[0] = 1, R[0] = 1;
        int i = 0;
        while (++i < N) {
            L[i] = L[i - 1] * nums[i - 1];
            R[i] = R[i - 1] * nums[N - i];
        }
        i = -1;
        while (++i < N)
            res[i] = L[i] * R[N - i - 1];
        return res;
    }
};
