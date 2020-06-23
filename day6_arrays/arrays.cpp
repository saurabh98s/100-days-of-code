#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(90);
    cout<<"SIze is "<<v.size()<<endl;
    v.clear();
    cout<<"SIze is "<<v.size()<<endl;
    return 0;
}