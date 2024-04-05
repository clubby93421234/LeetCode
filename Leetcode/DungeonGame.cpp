#include "DungeonGame.h"
//unfinished

int DungeonGame::helper(int i, int j, std::vector<std::vector<int>>& dungeon)
{
    //run outside of dungeon
    if (i > dungeon.size())
        return INT_MAX;
    if (j > dungeon[i].size())
        return INT_MAX;
    if (i == dungeon.size() && j == dungeon[dungeon.size() - 1].size())
        return dungeon[i][j];
    
    return std::min(helper(i+1,j,dungeon),helper(i,j+1,dungeon));
}

int DungeonGame::calculateMinimumHP(std::vector<std::vector<int>>& dungeon)
{
    int health = INT_MAX;
    


    return health;
}
