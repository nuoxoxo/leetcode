class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int hays = haystack.length();
        int nees = needle.length();
        int i, j;

        if (nees == 0)
            return 0 ;
        if (hays == 0 || nees > hays)
            return -1 ;
        i = -1;
        while (++i < hays - nees + 1)
        {
            j = 0;
            while (i + j < hays && haystack[i + j] == needle[j])
                ++j ;
            if (j == nees)
                return i;
        }
        return -1;
    }
};
