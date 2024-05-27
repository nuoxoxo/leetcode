class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        vector<int(*)(vector<int>&)> Solutions {
            // Bruteforce_custom_lower_bound,
            Bruteforce_std_lower_bound,
        };
        return Solutions[0](nums);
    }

    static int Bruteforce_std_lower_bound(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int N = nums.size();
        int curr = -1;
        while (++curr < N + 1)
        {
            auto L = std::lower_bound(begin(nums), end(nums), curr);
            if (curr == end(nums) - L)
                return curr;
        }
        return -1;
    }

    static int Bruteforce_custom_lower_bound(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int N = nums.size();
        int curr = -1;
        while (++curr < N + 1)
        {
            int l = 0, r = N;
            //  find bisect_left / lower_bound
            while (l < r)
            {
                int mid = (r - l) / 2 + l;
                {
                    int n = nums[mid];
                    if (n < curr)
                        l = mid + 1;
                    else
                        r = mid;
                }
            }
            if (curr == N - l)
            {
                return curr;
            }
        }
        return -1;
    }
};
