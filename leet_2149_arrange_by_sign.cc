class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<vector<int>(*)(vector<int>&)> Solutions {
            Solution_fixed_size_vi,
        };
        return Solutions[0](nums);
    }

    static vector<int> Solution_fixed_size_vi(vector<int> & nums) {
        int len = (int)nums.size();
        vector<int> res(len);
        int pos = 0;
        int neg = 1;
        for (int n: nums) {
            if (n < 0) {
                res[neg] = n;
                neg += 2;
            } else {
                res[pos] = n;
                pos += 2;
            }
        }
        return res;
    }
};
