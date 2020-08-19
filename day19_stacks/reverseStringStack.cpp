#include<iostream>
#include<stack>

using namespace std;

void Reverse(string input){
    stack<char>stck;
    for(int i=0; i<stck.size();i++){
        stck.push(input[i]);
        cout<<"pushing data:"<<input[i]<<endl;
    }

    for(int i=0; i<stck.size();i++){
        cout<<stck.top();
        stck.pop();
    }
    
}


int main() {
    string abc="012345";
    stack<char>stck;
    for(int i=0; i<abc.size();i++){
        stck.push(abc[i]);
        cout<<"pushing data:"<<abc[i]<<endl;
    }

    for(int i=0; i<abc.size();i++){
        cout<<stck.size()<<endl;
        cout<<"poping data:"<<stck.top()<<endl;
        stck.pop();
    }
}