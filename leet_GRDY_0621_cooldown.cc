class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        /*
        A A A B B B - n=2
        --->    A . . A . . A
        --->    A B . A B . A B     (8)

        A A A B B B - n=3
        --->    A . . . A . . . A
        --->    A B . . A B . . A B (10)_

        A A B B C D - n=1
        --->    A .    A
        --->    A B    A B
        --->    A B C  A B
        --->    A B C  A B D    (6)
        */
        int D[26] = {0};
        for (char c: tasks)
            D[c - 'A']++;
        sort(std::begin(D), std::end(D), greater<int>{});
        int N = (int) tasks.size();
        int segments = D[0] - 1;
        int mustcool = segments * n;
        int i = 0;
        while (++i < 26 && D[i])
            mustcool -= min(D[i], segments);
        if (mustcool > 0)
            return mustcool + N; // still cooldowns left
        return N; // all cooldowns are used
    }
};
