#include <iostream> 
#include <iterator> 
#include <map> 
#include<string>
  
using namespace std;

int main() {
    string str= "qwertyuiopq";
    map<string,int> table;
    for (string::size_type i = 0; i < str.size(); i++)
    {
        cout<<str[i]<<"\n";
        if (table.find(str[i])!=0)
        {
            /* code */
        }
        
    }
    
}

