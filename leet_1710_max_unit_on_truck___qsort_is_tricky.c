int     cmp(void *a, void *b);

int maximumUnits(int** t, int tsize, int* boxTypesColSize, int truckSize)
{
    qsort(t, tsize, sizeof(*t), cmp);
    int res, i, j;

    res = 0;
    i = -1;
    while (++i < tsize)
    {
        j = -1;
        while (++j < t[i][0])
        {
            if (truckSize < 1)
                return res;
            res += t[i][1];
            -- truckSize;
        }
    }
    /*
    i = -1;
    while (++i < tSize) printf("%d %d \n", t[i][0], t[i][1]);
    */
    return res;
        
}

int cmp(void *x, void *y)
{
    int     *a = *(int**) x;
    int     *b = *(int**) y;

    if (a[1] < b[1])
        return 1;
    if (a[1] == b[1])
        return a[0] < b[0];
    return 0 ;
}

//	below : verbose, also works no problem

/*
int cmp(void *a, void *b)
{
    if ((*(int **) a)[1] < (*(int **) b)[1])
        return 1;
    if ((*(int **) a)[1] == (*(int **) b)[1])
        if ((*(int **) a)[0] < (*(int **) b)[0])
            return 1;
    return 0 ;
}
*/
