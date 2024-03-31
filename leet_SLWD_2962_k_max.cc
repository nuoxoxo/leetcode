class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max = *max_element(begin(nums), end(nums));
        int N = nums.size();
        int l = 0, r = -1;
        int fq = 0;
        long long res = 0;
        while (++r < N) {
            if (nums[r] == max)
                fq++;
            if (fq < k)
                continue ;
            while (fq > k && l < r) {
                if (nums[l] == max)
                    fq--;
                l++;
            }
            while (nums[l] ^ max && l < r)
                l++;
            res += l + 1;
        }
        return res;
    }
};
