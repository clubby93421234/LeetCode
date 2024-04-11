#include "IndexofFirstOccurence.h"

int IndexofFirstOccurence::strStrITERATIV(std::string haystack, std::string needle)
{
	for (int i = 0; i < haystack.size(); i++)
	{
		if (haystack.substr(i,needle.size()) == needle) {
			return i;
		}
	}
    return -1;
}

int IndexofFirstOccurence::strStrRECURSIV(std::string haystack, std::string needle, int i)
{
	if (i >= haystack.size())
		return -1;
	if (haystack.substr(i, needle.size()) == needle) {
		return i;
	}
	return strStrRECURSIV(haystack, needle, i + 1);
     
}

int IndexofFirstOccurence::strStrRECdriver(std::string haystack, std::string needle)
{
	return strStrRECURSIV(haystack,needle,0);
}

int IndexofFirstOccurence::strStrFAST(std::string haystack, std::string needle)
{
	std::size_t found= haystack.find(needle);
	if (found != std::string::npos) {
		return found;
	}
	else {
		return -1;
	}

}
