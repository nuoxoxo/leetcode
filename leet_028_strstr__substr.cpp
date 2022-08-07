class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int hays = haystack.length();
        int nees = needle.length();
        int i;

        if (nees == 0)
            return 0 ;
        if (hays == 0 || nees > hays)
            return -1 ;
        i = -1;
        while (++i < hays - nees + 1)
            if (haystack.substr(i, nees) == needle)
                return i;
        return -1;
    }
};
