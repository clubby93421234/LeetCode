#include "Palindrome_Number.h"

bool Palindrome_Number::isPalindrome(int x)
{
    if (x < 0) {
        return false;
    }
    else {
        int reversed = 0;
        int temp = x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }
        return (x == reversed);
    }

}
