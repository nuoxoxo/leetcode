class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int len_hays = haystack.length();
        int len_need = needle.length();
        int i;
        int end;

        if (!len_need)
            return 0;
        if (!len_hays || len_hays < len_need)
            return -1;
        i = -1;
        end = len_hays - len_need + 1;
        while (++i < end)
        {
            if (haystack.substr(i, len_need) == needle)
                return i;
        }
        return -1;
    }
};
