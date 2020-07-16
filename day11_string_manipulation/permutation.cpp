#include<iostream>
#include<string>
#include<map>
#include <cstring> 
#include <cctype> 

using namespace std ;


bool checkPermutation(string str) {
    map<char,int> charMap;
    for (int i = 0; i < str.length(); i++)
    {
        // if (str[i] != ' ')
        if (isspace(str[i])!=true)
        {
            charMap[str[i]]++;
        }
        
    }
    int oddCount= 0;
    bool isPermutation= true;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]%2==1)
        {
            oddCount++;
        }
        if (oddCount >1)
        {
            isPermutation = false;
            break;
        }
        
        
    }
    return isPermutation;    
}

int main(int argc, char const *argv[])
{
    cout<<checkPermutation("Taaut")<<endl;
    cout<<checkPermutation("Tact Coa");
    return 0;
}

