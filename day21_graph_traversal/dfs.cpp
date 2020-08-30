#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Node {

    public:

    string name;
    vector <Node *> children;

    
    

    Node(string name){
        this->name = name;
    }


    vector<string> DFS(vector <string> * array){
        array->push_back(this->name);
        for (int i = 0; i < this->children.size(); i++)
        {
            children[i]->DFS(array);
            cout<<"Accessing Element "<<i<<" "<<children[i]->name<<endl;
        }
        
        
        

        return *array;
        
    }

    Node* addChild(string name){
        Node * child = new Node(name);
        children.push_back(child);
        cout<<child->name<<endl;
        return this;
    }
};

int main(){
  Node g("traverse1");
  g.addChild("string1");
  g.addChild("child1");
  g.addChild("child2");
  g.addChild("child3");
  g.addChild("child4");
  vector<string> new_array;
  g.DFS(&new_array);
  
  

  return 0;
}