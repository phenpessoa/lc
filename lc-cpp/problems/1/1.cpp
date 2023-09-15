#include <iostream>
#include <vector>
#include <unordered_map>

#include "1.h"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;

    unordered_map<int, int> m;
    int i = 0;
    for (int &n : nums)
    {
        size_t v = m.count(n);
        if (v)
        {
            return {m[n], i};
        }
        m[target - n] = i;
        ++i;
    }

    return result;
}

int main()
{
    if (!test_1())
    {
        cout << "test 1 failed\n";
    }
    else
    {
        cout << "test 1 passed\n";
    }

    if (!test_2())
    {
        cout << "test 2 failed\n";
    }
    else
    {
        cout << "test 2 passed\n";
    }

    if (!test_3())
    {
        cout << "test 3 failed\n";
    }
    else
    {
        cout << "test 3 passed\n";
    }

    return 0;
}

bool test_1()
{
    vector<int> nums = {2,
                        7,
                        11,
                        15};
    auto res = twoSum(nums, 9);
    if (res.size() != 2)
        return false;
    if (res[0] != 0 || res[1] != 1)
        return false;

    return true;
}

bool test_2()
{
    vector<int> nums = {3,
                        2,
                        4};
    auto res = twoSum(nums, 6);
    if (res.size() != 2)
        return false;
    if (res[0] != 1 || res[1] != 2)
        return false;

    return true;
}

bool test_3()
{
    vector<int> nums = {3,
                        3};
    auto res = twoSum(nums, 6);
    if (res.size() != 2)
        return false;
    if (res[0] != 0 || res[1] != 1)
        return false;

    return true;
}