/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

class Solution {
public:
    bool validMountainArray(vector<int>& arr)
    {
        if (arr.size() < 3) return false ;

        bool asc = false, des = false;
        int i = 1;

        while (i < arr.size() && arr[i] > arr[i - 1])
        {
            asc = true;
            i++;
        }
        while (i < arr.size() && arr[i] < arr[i - 1])
        {
            des = true;
            i++;
        }
        if (i == arr.size() && asc && des)  return true ;
        return false ;
    }
};
