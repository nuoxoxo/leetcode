class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {

        vector<int(*)(vector<int>&, int)> Solutions {
            solution_nCubed,
        };
        return Solutions[0](nums, k);
    }

    static int solution_nCubed(vector<int>& nums, int k) {

        int res = 0;
        int N = nums.size();
        int i = -1, j;
        while (++i < N)
        {
            j = i - 1;
            int n = nums[i];
            while (++j < N)
            {
                n = std::gcd(n, nums[j]);
                if (n == k)
                    res++;
            }
        }
        return res;
    }
};
