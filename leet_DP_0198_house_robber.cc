class Solution {
public:
    int rob(vector<int>& nums) {
        vector< int (*)(std::vector<int> & )> Solutions {
            Solution_Top_Down_DP,
            Solution_Classic_DP,
            Solution_Constant_Space,
        };
        return Solutions[ std::rand() % Solutions.size() ]( nums );
    }
    // Constant Space DP
    static int Solution_Constant_Space (vector<int> & nums) {
        int len = (int) nums.size();
        if (len < 3)
            return * std::max_element(nums.begin(), nums.end());
        int curr = 0;
        int prevprev = 0;
        for (int n: nums) {
            int temp = curr;
            curr = max( curr, prevprev + n );
            prevprev = temp;
        }
        return curr;
    }
    // Top-Down DP
    static int Solution_Top_Down_DP (vector<int> & nums) {
        int len = (int) nums.size();
        if (len < 3)
            return * std::max_element(nums.begin(), nums.end());
        // using memo to prevent TLE
        vector<int> memo(len, -1);
        return dp( nums, memo, nums.size() - 1 );
    }
    static int dp (vector<int>& nums, vector<int> &memo, int index) {
        if (index < 0)
            return 0;
        if (memo[index] > -1) {
            return memo[index];
        }
        int prev = dp(nums, memo, index - 1);
        int prevprev = dp(nums, memo, index - 2) + nums[index];
        int curr = std::max(prev, prevprev);
        memo[index] = curr;
        return curr;
    };
    // Classic DP
    static int Solution_Classic_DP (vector<int> & nums) {
        int len = (int) nums.size();
        if (len < 3)
            return * std::max_element(nums.begin(), nums.end());
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        dp[2] = max(nums[1], nums[0] + nums[2]);
        int i = 2;
        while (++i < len) {
            dp[i] = max( dp[i - 1], nums[i] + dp[i - 2] );
        }
        return dp[ len - 1 ];
    }
};
