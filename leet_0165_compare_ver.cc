class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        int i, j, len1, len2, res1, res2;

        len1 = version1.length();
        len2 = version2.length();
        res1 = res2 = i = j = 0 ;
        while (i < len1 || j < len2)
        {
            while (i < len1 && version1[i] ^ '.')
            {
                res1 += version1[i] - '0' + res1 * 10;
                i++;
            }
            while (j < len2 && version2[j] ^ '.')
            {
                res2 += version2[j] - '0' + res2 * 10;
                j++;
            }
            if (res1 < res2)    return -1 ;
            if (res1 > res2)    return 1 ;
            res1 = res2 = 0;
            ++i;
            ++j;
        }
        return 0 ;
    }
};
