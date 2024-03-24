class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        vector<int(*)(vector<int>&)> Solutions {
            Binary_search,
            // Naive,
        };
        return Solutions[0](nums);
    }

    static int Binary_search(vector<int>& nums)
    {
        int N = (int) nums.size();
        if (N < 3)
            return nums[0];
        int mid = N / 2;
        sort(nums.begin(), nums.end());
        if (nums[mid - 1] == nums[mid] || nums[mid] == nums[mid + 1])
            return nums[mid];
        int l = 1, r = N - 2;
        while (l < mid && mid < r)
        {
            if (nums[l - 1] == nums[l]) return nums[l];
            if (nums[r + 1] == nums[r]) return nums[r];
            ++l;
            --r;
        }
        assert(false);
        return nums[mid];
    }

    static int Naive(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (++i < (int)nums.size())
            if (nums[i - 1] == nums[i])
                break ;
        return nums[i];
    }
};
