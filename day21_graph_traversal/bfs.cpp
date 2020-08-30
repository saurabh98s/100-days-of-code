#include <vector>
#include <iostream>
#include <string>
#include<deque>

using namespace std;

class Node {

    public:

    string name;
    vector <Node *> children;

    Node(string name){
        this->name= name;
    }

    vector<string> BFS(vector<string> * array){
        deque<Node* > queue{this};

        int counter=0;
        while(!queue.empty()){
            Node  current = *queue.front();
            queue.pop_front();
            array->push_back(current.name);
            for (int i = 0; i < current.children.size(); i++)
            {
                queue.push_back(current.children[i]);
            }
            
        }
        return *array;
    }  
};