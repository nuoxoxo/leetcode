class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int N = (int)nums.size();
        sort( nums.begin(), nums.end() );
        long long curr = nums[0];
        long long res = 0;
        int i = 0;
        while (++i < N) {
            if (nums[i] < curr)
                res = curr + nums[i];
            curr += nums[i];
        }
        return res ? res : -1;
    }
};
