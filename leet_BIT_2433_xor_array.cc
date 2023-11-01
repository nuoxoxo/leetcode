class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        //  way 1 - return a new array
        /*
        int len = (int) pref.size(), i = 0;
        vector<int> res{pref[0]};
        while (++i < len)
            res.push_back(pref[i] ^ pref[i - 1]);
        return res;
        */
        //  way 2 - in place
        int i = (int) pref.size();
        while (--i > 0)
            pref[i] = pref[i] ^ pref[i - 1];
        return pref;
    }
};
