#include <stdio.h>
#include <stdlib.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int ai = 0, bj = 0, ck = 0, length = 0;
    int *res = NULL;
    double result;
    length = nums1Size + nums2Size;
    res = (int *)malloc(length*sizeof(int));
    for (ck=0; ck< length; ck++){
        if(ai == nums1Size)
        {
            res[ck] = nums2[bj];
            bj++;
        }
        else if(bj == nums2Size)
        {
            res[ck] = nums1[ai];
            ai++;
        }
        else
        {
            if(nums1[ai] < nums2[bj])
            {
                res[ck] = nums1[ai];
                ai++;
            }
            else
            {
                res[ck] = nums2[bj];
                bj++;
            }
        }
        
    }
    for (ck = 0; ck < length;ck++)
    {
        printf("%d ", res[ck]);
    }
        if (length % 2 == 0)
            result = (res[length / 2 - 1] + res[length / 2]) / 2.0;
        else
            result = res[length / 2];
    return result;
}

int main()
{
    int nums1[2] = {1, 3};
    int nums2[2] = {2, 4};
    double i = 0;
    //int *c = NULL;
    //c = findMedianSortedArrays(nums1, 4, nums2, 4);
    i = findMedianSortedArrays(nums1, 2, nums2, 2);
    printf("%lf ", i);
    return 0;
}