class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector< long long (*) (vector<int> &) > Solutions {
            // Reverse_Sorting_Greedy, // DRAFT - WRONG
            Sorting_and_Greedy,
        };
        return Solutions[ 0 ]( nums );
    }

    // WRONG
    /*
    static long long Reverse_Sorting_Greedy (vector<int> & nums) {
        sort( nums.begin(), nums.end() );
        int N = (int) nums.size();
        assert (N > 2);
        int i = N;
        while (--i > 1) {
            long long prev2nums = nums[i - 1] + nums[i - 2] ;
            cout << i << ' ' << nums[i] << ' ' << prev2nums << endl;
            if ( nums[i] < prev2nums )
                return nums[i] + prev2nums;
        }
        return -1;
    }
    */

    static long long Sorting_and_Greedy (vector<int> & nums) {
        int N = (int)nums.size();
        sort( nums.begin(), nums.end());
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
