// DFS algorithm in C++

#include <iostream>
#include <list>
using namespace std;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

public:
    // Initialize graph
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
        visited = new bool[vertices];
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_front(dest);

    }

  void DFS(int vertex) {

        visited[vertex] = true;
        list<int> adjList = adjLists[vertex];

        cout << vertex << " ";

        list<int>::iterator i;
        for (i = adjList.begin(); i != adjList.end(); ++i)
            if (!visited[*i])
            DFS(*i);
    }
};


int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  g.DFS(3);

  return 0;
}
