class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        int             i = -1, len1 = nums1.size(), len2 = nums2.size();
        vector<int>     res(nums1.size(), -1);
        map<int, int>   mp ;
        deque<int>      dq ;
        

        while (++i < len2)
        {
            if (dq.empty() || dq.front() > nums2[i])
                dq.push_front(nums2[i]);
            else
            {
                mp[dq.front()] = nums2[i];
                dq.pop_front();
                --i;
            }
        }
        i = -1;
        while (++i < len1)
        {
            int t = nums1[i] ;
            if (mp.find(t) != mp.end())
                res[i] = mp[t];
        }
        return res ;
    }
};
