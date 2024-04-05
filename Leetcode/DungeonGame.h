#pragma once
#include <vector>
class DungeonGame
{
	int helper(int i, int j,std::vector<std::vector<int>>& dungeon);
	int calculateMinimumHP(std::vector<std::vector<int>>& dungeon);
};

