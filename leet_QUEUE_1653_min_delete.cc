class Solution {
public:
    int minimumDeletions(string s)
    {
        // Eg.1
        // aababbab - Rule is no B before A, ie. no AB in a stack
        //        ^ b
        //       ^^ ba
        //      ^   b(a + b) ---> b
        //     ^^   b
        //    ^^^   bba
        //   ^      bb(a + b) ---> b
        // ^^^      bba
        // ... so once we meet B after an A, negate them as a pair

        // Eg.2
        // bbaaaaabb
        //  ^^^^^^^^ bbaaaa(a + b) ---> bbaaaa
        // ^  ^^^^^^ bbaaa(a + b) ---> bbaaa

        int res = 0;
        int N = s.length();
        deque<int> Q;
        int i = N;
        while (--i > -1)
        {
            if (!Q.empty() && s[i] == 'b' && Q.back() == 'a')
            {
                res++;
                Q.pop_back();
            }
            else
                Q.push_back(s[i]);
        }
        return res;
    }
};
