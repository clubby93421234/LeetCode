#include "CombinationSumIII.h"

void CombinationSumIII::backtrack(int i, int k, std::vector<int> comb, std::vector<std::vector<int>> res, int n)
{
    if (comb.size()==k && n==0) {
        res.emplace_back(comb);
        return;
    }
    if (n<0 || comb.size()>=k) {
        return;
    } 
    for (int j = i; j <= 9; ++j) {
        comb.push_back(j);
        backtrack(j + 1, k, comb, res,n - j);
        comb.pop_back();
    }
}
std::vector<std::vector<int>> CombinationSumIII::combinationSum3(int k, int n)
{  
    std::vector<std::vector<int>> result;
    std::vector<int> comb;
    backtrack(1,k, comb, result, n);
    return result;
}
