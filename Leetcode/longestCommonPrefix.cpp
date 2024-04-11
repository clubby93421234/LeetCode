#include "longestCommonPrefix.h"
#include <algorithm>

std::string longestCommonPrefix::longestCommonPrefixMethod(std::vector<std::string>& strs)
{
	
    
	std::string result = "";
if (strs.empty())
	{
	return result;
	}
if (strs.size() == 1)
{
	return strs[0];
}
std::sort(strs.begin(),strs.end());
	std::string first = strs[0];
	std::string last = strs[strs.size()-1];
	for (int i = 0; i < std::min(first.size(), last.size()); i++)
	{
		if (first[i]==last[i]) {
			result+=first[i];
		}
		else {
			return result;
		}
	}
    return result;
}
