//
// Created by Sifat Ali on 11/22/2023.
//
#include <iostream>
#include <list>
using namespace std;

class Edge{
public:
    int src;
    int dis;
    int weight;
    Edge(int src,int dis,int weight){
        this->src=src;
        this->dis=dis;
        this->weight=weight;
    }
};

void printNeighbour( list<Edge> Graph[],int point){
    cout << "Vertix " << point << " Neighbor :";
    for (Edge e: Graph[point]) {
        cout << e.dis << " ";
    }
    cout << endl;
}

void display( list<Edge> Graph[],int v){
    for (int i = 0; i < v; i++) {
        cout<<"Vertix "<< i<<":";
        for ( Edge e:Graph[i]) {
            cout << "(" << e.src << "->" << e.dis << ") "<< " Weight : " << e.weight<<" ";
        }
        cout << endl;
    }
}


int main(){
    int v=4;
    list<Edge> Graph[v];

    Graph[0].push_back(Edge(0,2,2));

    Graph[1].push_back(Edge(1,2,10));
    Graph[1].push_back(Edge(1,3,3));

    Graph[2].push_back(Edge(2,0,2));
    Graph[2].push_back(Edge(2,1,10));
    Graph[2].push_back(Edge(2,2,-1));

    Graph[3].push_back(Edge(3,1,0));
    Graph[3].push_back(Edge(3,2,-1));

    display(Graph, v);
    printNeighbour(Graph,2);

}