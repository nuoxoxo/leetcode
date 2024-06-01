class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int res = 0, i = -1, j;
        while (++i < nums1.size())
        {
            j = -1;
            while (++j < nums2.size())
            {
                int mult = nums2[j] * k;
                if ( nums1[i] % mult == 0 )
                    ++res;
            }
        }
        return res;
    }
};
