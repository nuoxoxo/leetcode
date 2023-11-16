class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        string  res;
        int n = (int)nums.size();
        int i = -1;
        while (++i < n)
            nums[i][i] == '0' ? res += '1' : res += '0';
        return res;
    }
};
