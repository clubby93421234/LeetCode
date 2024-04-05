#include "HouseRobberII.h"
#include <stack>
#include<algorithm>
int HouseRobberII::rob(std::vector<int>& nums)
{
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return std::max(nums[0],nums[1]);
    //rob houses 0 to n-2
    //rob houses 1 to n-1

    int first = 0;
    int sec = 0;
   
    int pre = 0, cur = 0;
    for (int i = 0; i <= nums.size()-2; i++)
    {
        int temp = std::max(pre + nums[i], cur);
        pre = cur;
        cur = temp;
    }
    first = cur;

    pre = 0;
    cur = 0;
    for (int i = 1; i <= nums.size() - 1; i++)
    {
        int temp = std::max(pre + nums[i], cur);
        pre = cur;
        cur = temp;
    }
    sec = cur;
    return std::max(first,sec);
}
