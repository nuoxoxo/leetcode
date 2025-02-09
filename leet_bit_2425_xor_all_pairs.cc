class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    {
        int x1 = 0, x2 = 0, n1 = nums1.size(), n2 = nums2.size();
        if (!(n1 % 2) && !(n2 % 2))
            return 0;
        for (int n: nums1) x1 ^= n;
        if (!(n1 % 2))
            return x1;
        for (int n: nums2) x2 ^= n;
        if (!(n2 % 2))
            return x2;
        return x1 ^ x2;
    }
};
