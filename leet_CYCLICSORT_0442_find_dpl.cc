class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<vector<int>(*)(vector<int> &)> Solutions {
            Cyclic_sort_in_place,
        };
        return Solutions[0](nums);
    }

    static vector<int> Cyclic_sort_in_place(vector<int> & nums) {
        vector<int> res;
        int N = nums.size();
        int i = 0;
        while (i < N)
        {
            if (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
                continue ;
            }
            ++i;
        }
        i = -1;
        while (++i < N)
            if (nums[i] != i + 1)
                res.push_back(nums[i]);
        return res;
    }
};
