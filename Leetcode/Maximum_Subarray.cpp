#include "Maximum_Subarray.h"

int Maximum_Subarray::maxSubArray(std::vector<int>& nums)
{
    int best_sum = nums[0];
    int current_sum = 0;
    if (nums.size() == 1) {
        return nums[0];
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        current_sum = std::max(nums[i], current_sum + nums[i]);
        best_sum = std::max(best_sum, current_sum);
    }
    return best_sum;

}
