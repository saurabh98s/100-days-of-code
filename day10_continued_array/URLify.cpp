#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iterator>
#include <map>
#include <iostream>
using namespace std;

void URLify(char *str, int len)
{
    int numSpaces = 0;
    int i = 0, j = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            ++numSpaces;
        }
    }
    int extendedLen = len + (2 * numSpaces);
    i = extendedLen-1;
    for (j = len - 1; j >= 0; --j)
    {
        if (str[j] != ' ')
        {
            str[i--] = str[j];
        }
        else
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
}

int main()
{
    char str[] = "Mr John Smith    "; //String with extended length ( true length + 2* spaces)
    std::cout << "Actual string   : " << str << std::endl;
    URLify(str, 13); //Length of "Mr John Smith" = 13
    std::cout << "URLified string : " << str << std::endl;
    return 0;
}