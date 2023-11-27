//DFS
// Created by Sifat Ali on 11/27/2023.
//
#include <iostream>
#include <list>

using namespace std;


class Edge{
public:
    int dis;
    Edge(int dis){
        this->dis= dis;
    }
};
struct  Queue{
    int data;
    struct Queue* next;
};
typedef struct  Queue node;
node* front= nullptr;
node* rear= nullptr;

bool isEmpty(){
    return rear== nullptr;
}

void push(int value){
    node* temp =new node;
    temp->data=value;
    temp->next=front;
    front=temp;

    rear->next = temp;
    rear = temp;
}

int pop(){
    if(front==nullptr ){
        cout<<"stack empty";
        return 0;
    }

    node* temp=front;
    int v=temp->data;
    front=front->next;
    free(temp);


    return v;
}

void check(int v, bool visited[], list<Edge> Graph[]) {
    visited[v] = true;
    cout << v << " ";


    for (Edge e: Graph[v]) {
        int adjacentVertex = e.dis;
        if (!visited[adjacentVertex]) {
            check(adjacentVertex, visited, Graph);
        }
    }

}

void DFS( list<Edge> Graph[],int size){
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            check(i, visited, Graph);
        }
    }
}


int main(){
    int v=4;

    list<Edge> Graph[v];
    Graph[0].push_back(Edge(2));

    Graph[1].push_back(Edge(2));
    Graph[1].push_back(Edge(3));

    Graph[2].push_back(Edge(0));
    Graph[2].push_back(Edge(1));
    Graph[2].push_back(Edge(3));

    Graph[3].push_back(Edge(1));
    Graph[3].push_back(Edge(2));

    cout<<"DFS : ";
    DFS(Graph,v);

}