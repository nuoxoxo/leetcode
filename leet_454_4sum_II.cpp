class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        map<int, int>    mp ;
        
        int i, j, res = 0;
        i = -1;
        while (++i < nums1.size())
        {
            j = -1;
            while (++j < nums2.size())  mp[nums1[i] + nums2[j]]++;
        }
        i = -1;
        while (++i < nums3.size())
        {
            j = -1;
            while (++j < nums4.size())  res += mp[-nums3[i] - nums4[j]] ;
        }

        return res ;
    }
};
