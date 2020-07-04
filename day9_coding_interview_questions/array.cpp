#include<vector>
#include<string>
#include<iostream>
#include<bitset>

using namespace std;

bool isUnique(const string &str) {
    if (str.length()>128)
    {
        return false;
    }
    vector <bool> char_set(128);
    for (int i = 0; i < str.length(); i++)
    {
        int val=str[i];
        if (char_set[val])
        {
            return false;

        }
        char_set[val]=true;
        return true;
        
    }

}

int main(int argc, char const *argv[])
{
    cout<<isUnique("Hello")<<endl;
    cout<<isUnique("helo")<<endl;
    cout<<isUnique("HelLo")<<endl;
    return 0;
}