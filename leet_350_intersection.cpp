/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>     res;
        map<int, int>   mp;
        int             i;
        
        i = -1;
        while (++i < nums1.size())
            mp[nums1[i]]++;
        i = -1; 
        while (++i < nums2.size())
        {
            if (mp[nums2[i]] > 0)
            {
                res.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return (res);
    }
};
