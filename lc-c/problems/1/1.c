#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../../hashmaps/ihm/ihm.h"
#include "1.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    IntHashMap *m = IHM_new();
    if (!m)
        return NULL;

    for (int i = 0; i < numsSize; ++i)
    {
        const int n = nums[i];
        const int *v = IHM_get(m, n);
        if (v)
        {
            *returnSize = 2;
            int *out = (int *)malloc(sizeof(int) * 2);
            if (!out)
                return NULL;

            out[0] = *v;
            out[1] = i;

            return out;
        }
        IHM_set(m, target - n, i);
    }

    return NULL;
}

int main()
{
    if (!test_1())
    {
        printf("test 1 failed\n");
    }
    else
    {
        printf("test 1 passed\n");
    }

    if (!test_2())
    {
        printf("test 2 failed\n");
    }
    else
    {
        printf("test 2 passed\n");
    }

    if (!test_3())
    {
        printf("test 3 failed\n");
    }
    else
    {
        printf("test 3 passed\n");
    }

    return 0;
}

bool test_1()
{
    int nums[4] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int returnsize = 0;

    int *res = twoSum(nums, numsSize, target, &returnsize);
    if (!res)
        return false;

    if (returnsize != 2)
    {
        free(res);
        return false;
    }

    if (res[0] != 0 || res[1] != 1)
    {
        free(res);
        return false;
    }

    return true;
}

bool test_2()
{
    int nums[3] = {3, 2, 4};
    int numsSize = 3;
    int target = 6;
    int returnsize = 0;

    int *res = twoSum(nums, numsSize, target, &returnsize);
    if (!res)
        return false;

    if (returnsize != 2)
    {
        free(res);
        return false;
    }

    if (res[0] != 1 || res[1] != 2)
    {
        free(res);
        return false;
    }

    return true;
}

bool test_3()
{
    int nums[2] = {3, 3};
    int numsSize = 2;
    int target = 6;
    int returnsize = 0;

    int *res = twoSum(nums, numsSize, target, &returnsize);
    if (!res)
        return false;

    if (returnsize != 2)
    {
        free(res);
        return false;
    }

    if (res[0] != 0 || res[1] != 1)
    {
        free(res);
        return false;
    }

    return true;
}