#include "SingleNumber.h"

int SingleNumber::singleNumber(std::vector<int>& nums)
{
	int ans = 0;
	for (auto& x : nums)
		ans ^= x;
	return ans;
    
}
// Using XOR i have 2 inputs. They are the same and cancel each pther out. The only single
// input remains at the end
/*
XOR
A B Y
0 0 0
0 1 1
1 0 1
1 1 0
*/