class Solution {
public:
    string  reverseVowels(string s)
    {
            bool            isVowel[CHAR_MAX] = { false };
            int             size, i;
            vector<int>     v;

            isVowel['A'] = true;
            isVowel['E'] = true;
            isVowel['I'] = true;
            isVowel['O'] = true;
            isVowel['U'] = true;
            isVowel['a'] = true;
            isVowel['e'] = true;
            isVowel['i'] = true;
            isVowel['o'] = true;
            isVowel['u'] = true;

            i = -1;
            while (++i < s.length())
                if (isVowel[s[i]])
                    v.push_back(i);
            size = v.size();
            if (!size || size == 1)
                return (s);
            i = -1;
            while (++i < size / 2)
                swap(s[v[i]], s[v[size - 1 - i]]);
            return (s);
    }
};
