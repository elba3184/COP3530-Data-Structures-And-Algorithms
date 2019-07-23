/** Elba Chimilio
 * COP3530-Section 7303
 * Project 3: Implementation of Dijkstra's algorithm using adjacency lists
*/

#include <iostream>
#include <queue>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> paifOfVer;

class Graphs_P3{
    
    //creates adjacency list to store the vertices, edges, and weights
    struct adjList{
 
        adjList *nextNode;
        adjList() = default;
        bool head;
        int weight;
        int value;
        int numEdges = 0;
        
        adjList(int value, bool isHead, int weight, adjList* nextNode){
            this->value = value;
            head = isHead;
            this->weight = weight;
            this->nextNode= nextNode;
        }
        
    };

private:

    const int a = numeric_limits<int>::max(); //Sets integer to infinity
    const static int MAX_VERTICES = 51;
    adjList vertexArray[MAX_VERTICES];
    int numVertices = 0;
    int findVertex[MAX_VERTICES];
    
public:
    
    Graphs_P3(){
        for(int i = 0; i < MAX_VERTICES; i++){
            findVertex[i] = 0;
        }
        
    }

    void insertVertex(int vertex); //inserts new vertex in graph
    void insertEdge(int from, int to, int weight); //inserts new edge in graph
    bool isEdge(int from, int to); //returns true if there is an edge between the vertices from and to
    int getWeight(int from, int to); //returns the weight of the edge between the vertices from and to
    vector<int> getAdjacent(int vertex); //return an array of integers representing vertices adjacent to vertex
    void printDijkstra(int source); //prints result of running Dijkstra algorithm with source vertex
    void printGraph(); //prints graph in a format sorted by ascending vertex and edge list
    bool isVertex(int vertex);//Check is vertex is in list
};

//Computational Complexity: O(1)
void Graphs_P3::insertVertex(int vertex){
 
    vertexArray[vertex] = adjList(vertex, true, -999, nullptr);
    findVertex[vertex] = 1;
    numVertices++;
    
}

//Computational Complexity: O(n)
//Where n is the number of vertices in the graph
void Graphs_P3::insertEdge(int from, int to, int weight){
 
    if(!isVertex(from)){
        insertVertex(from);
    }

    if (!isVertex(to)){
        insertVertex(to);
    }

    adjList *head = &vertexArray[from];
    adjList *current = head;
    adjList *newEdge = new adjList(to, false, weight, nullptr);

    while (current->nextNode != nullptr){
        current = current->nextNode;
    }

    current->nextNode = newEdge;
    head->numEdges = head->numEdges + 1;
    
}

//Computational Complexity: O(n)
//Where n is the number of vertices in the graph
bool Graphs_P3::isEdge(int from, int to){
 
    adjList *current = &vertexArray[from];
    while(current != nullptr){
        if(current->value == to){
            return true;
        }
        current = current->nextNode;
    }
    return false;
    
}

//Computational Complexity: O(n)
//Where n is the number of vertices in the graph
int Graphs_P3::getWeight(int from, int to){
 
    adjList *current = &vertexArray[from];

    while (current != nullptr){
        if(current->value == to){
            return current->weight;
        }
        current = current->nextNode;
    }
    return numeric_limits<int>::max();
    
}

//Computational Complexity: O(nlog(n))
//Where n is the number of vertices in the graph which executes n times
vector<int> Graphs_P3::getAdjacent(int vertex){
 
    adjList *current = &vertexArray[vertex];
    vector<int> arr;
    current = current->nextNode;

    while (current != nullptr) {
        arr.push_back(current->value);
        current = current->nextNode;
    }
    
    sort(arr.begin(), arr.end());
    return arr;
    
}

//Computational Complexity: O(mlog(n))
//Where n is the number of vertices in the graph
//And m is number of edges in in the graph
void Graphs_P3::printDijkstra(int source){
 
    priority_queue<paifOfVer, vector<paifOfVer>, greater<paifOfVer>> minHeap; //Creates a min-heap
    vector<int> weights(MAX_VERTICES, a); //Contains weights in vector
    string thePath = to_string(source);
    vector<string> paths(MAX_VERTICES, thePath);//Vector containing the paths from one vertex to another
    minHeap.push(make_pair(0, source));
    weights[source] = 0;
    
    while(!minHeap.empty()){
        int D = minHeap.top().second;//Sets the shortest distance to source vertex
        minHeap.pop(); //pops from minHeap
        adjList *top = &vertexArray[D];
        adjList *adjacentTop = top->nextNode; 

        //Checks if there is a shorter path to the source vertex, if there is, the value is changed and it updates the path
        //It then updates the minheap with the pair
        while(adjacentTop != nullptr){
            if (weights[adjacentTop->value] > weights[top->value] + adjacentTop->weight){
                weights[adjacentTop->value] = weights[top->value] + adjacentTop->weight;
                paths[adjacentTop->value] = paths[top->value] + "-" + to_string(adjacentTop->value); 
                minHeap.push(make_pair(weights[adjacentTop->value], adjacentTop->value));
            }
            adjacentTop = adjacentTop->nextNode;
        }
    }

   //Prints table
    int counter = 1;
    cout<< "V D P\n";
    for (int i = 0; i < MAX_VERTICES; ++i){
        if (i != source){
            if(findVertex[i] == 1){
                cout << i << " " << weights[i] << " " << paths[i];
                counter++;
                if (counter != numVertices){
                    cout << "\n";
                }
            }
        }
    }
    
}

//Computational Complexity: O(n*mlog(m))
//Where n is MAX_VERTICES
//And m is the number of edges per vertex
void Graphs_P3::printGraph(){
 
    int counter = 0;
    for (int i = 0; i < MAX_VERTICES; i ++){
        if (findVertex[i] == 1) {
            cout << vertexArray[i].value;
            vector<int> adjacent = getAdjacent(vertexArray[i].value);
            int size = adjacent.size();
            int j;
            j=0;
            while(j<size){
                cout<< " " << adjacent[j];
                j++;
            }
            counter++;
            if (counter != numVertices){
                cout << "\n";
            }
        }
    }
    
}

//Computational Complexity: O(1)
bool Graphs_P3::isVertex(int vertex){
 
    if (findVertex[vertex] == 0){
        return false;
    }else{
        return true;
    }
    
}

//---------------------------//PROVIDED CODE//---------------------------------------//
int main(){
    //DO NOT CHANGE THIS FUNCTION. CHANGE YOUR IMPLEMENTATION CODE TO MAKE IT WORK
    int noOfLines, operation, vertex, to, fro, weight,source,j;
    vector<int> arr;
    int arrSize;
    Graphs_P3 g;
    cin>>noOfLines;
    
    for(int i=0;i<noOfLines;i++){
        cin>>operation;
        switch(operation){
            case 1:
                cin>>vertex;
                g.insertVertex(vertex);
                break;
            case 2:
                cin>>fro;
                cin>>to;
                cin>>weight;
                g.insertEdge(fro,to,weight);
                break;
            case 3:
                cin>>fro;
                cin>>to;
                cout<<g.isEdge(fro,to)<<"\n";
                break;
            case 4:
                cin>>fro;
                cin>>to;
                cout<<g.getWeight(fro,to)<<"\n";
                break;
            case 5:
                cin>>vertex;
                arr=g.getAdjacent(vertex);
                arrSize = arr.size();
                j=0;
                while(j<arrSize)
                {
                    cout<<arr[j]<<" ";
                    j++;
                }
                cout<<"\n";
                break;
            case 6:
                cin>>source;
                g.printDijkstra(source);
                cout<<"\n";
                break;
            case 7:
                g.printGraph();
                cout<<"\n";
                break;
        }
    }
    
}
//-----------------------------------------------------------------------------------//