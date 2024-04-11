#include "LongestSubsting.h"

int LongestSubsting::lengthOfLongestSubstring(std::string s)
{
	int maxLength = 0;
	int left = 0;

	for (int i = 0; i < s.size(); i++)
	{
		//if char is not in our map or its position is left from left side of substring
		if (subs.count(s[i])==0 ||subs[s[i]]<left) {
			//update char
			subs[s[i]]=i;
			//updae maxLength
			maxLength = std::max(maxLength, i-left);
		}
		else {
			//move left side to the current repeating char. "abbbbabb"--> left from first "a" to second "a"
			left = subs[s[i]]+1;
			subs[s[i]] = i;
		}
	}
    
    return maxLength;
}
