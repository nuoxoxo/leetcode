/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* n, int nsize, int* rsize)
{
    int *res;
    if (!(res = (int*) malloc(sizeof(int) * nsize)))
        return NULL;
    *rsize = nsize;
    int run = 0;
    int i = -1;
    while (++i < nsize)
    {
        run += n[i];
        res[i] = run;
    }
    return res;
}
