/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize)
{

    int N = strlen(s);
    int * res = malloc(sizeof(int) * (N + 1));
    if (!res)
        return res;
    int L = 0;
    int R = N;
    int i = -1;
    while (++i < N)
    {
        char c = s[i];
        if (c == 'D')
        {
            res[i] = R--;
        }
        else if (c == 'I')
        {
            res[i] = L++;
        }
    }
    res[N] = L;
    * returnSize = N + 1;
    return res;
}
