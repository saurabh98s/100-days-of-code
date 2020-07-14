#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iterator> 
#include <map>
#include <iostream>
using namespace std;


bool arePermutation(string str1, string str2){
    if (str1.length() !=str2.length()) {
        return false;
    }
    // sort the strings
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i]!=str2[i])
        {
            return false;
        }
        
        
    }
    return true;
    

}

bool arePermutationMap(string str1,string str2) {
    if (str1.length() !=str2.length()) {
        return false;
    }
    int count[256];

    for (int i = 0; i < str1.length(); i++)
    {
        int val=str1[i]; //type cast to ascii value
        count[val]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        int val=str2[i]; //type cast to ascii value
        count[val]--;
        if (count[val]<0){
            return false;
        }
        return true;
    }
    
}


int main(int argc, char const *argv[])
{
    string a="pasta";
    string b="astap";
    cout<<arePermutation(a,b)<<endl;
    cout<<arePermutationMap(a,b);
    return 0;
}
