#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int main(){
    list<int> v;

    v.push_back(1120);
    v.push_back(5);
    v.push_back(50);
    v.push_back(490);
    list<int>::iterator iter =v.begin();
    sort(v.begin(),v.end());
    // auto iter = v.begin();
    cout<<"SIze is "<<v.size()<<endl;
    for (;iter!=v.end(); iter++)
    {
        cout<<"Value is:"<<*iter<<endl;
    }
    
    return 0;
}