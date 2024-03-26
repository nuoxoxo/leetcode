class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        vector<int(*)(vector<int> &)> Solutions {
            Cyclic_sort,
        };
        return Solutions[0](nums);
    }

    static int Cyclic_sort(vector<int>& nums)
    {
        // Cyclic sort - idea :
        //      sorting - place each number at its correct index - (sorting)
        //      inspect - find the 1st index where its element does not match
        int N = nums.size();
        int i = 0;
        while (i < N)
        {
            //  IF : nums[i] not in correct position AND in range [ 1, N ]
            //  TODO : swap
            if (0 < nums[i] && nums[i] <= N)
            {
                int idx = nums[i] - 1;
                if (nums[ idx ] ^ nums[i])
                    swap(nums[i], nums[idx]);
                else
                    ++i;
            }
            else
                ++i;
        }
        i = -1;
        while (++i < N)
            if (nums[i] ^ i + 1)
                return i + 1;
        return N + 1;
    }
};
