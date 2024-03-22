#include "Two_Sum.h"

std::vector<int> Two_Sum::twoSum_bruteForce(std::vector<int>& nums, int target)
{
	for (int i = 0; i < nums.size() - 1; i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target) {
				return { i,j };
			}
		}

	}
	return {};
}

std::vector<int> Two_Sum::twoSum(std::vector<int>& nums, int target)
{
	std::unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++)
	{
		int complement = target - nums[i];
		auto it = map.find(complement);
		if (it != map.end()) {
			return std::vector<int>{i, it->second};
		}
		else {
			map.emplace(nums[i], i);
		}
	}
	return std::vector<int>{};
}
