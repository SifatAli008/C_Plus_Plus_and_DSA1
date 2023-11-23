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
    Edge(int src,int dis){
        this->src=src;
        this->dis=dis;
    }
};

void printNeighbour( list<Edge> Graph[],int point){
    cout << "Edge " << point << " Neighbor :";
    for (Edge e: Graph[point]) {
        cout << e.dis << " ";
    }
    cout << endl;
}

void display( list<Edge> Graph[],int v){
    for (int i = 0; i < v; i++) {
        cout<<"Edge "<< i<<":";
        for ( Edge e:Graph[i]) {
            cout << "(" << e.src << "->" << e.dis << ") ";
        }
        cout << endl;
    }
}


int main(){
    int v=4;
    list<Edge> Graph[v];

    Graph[0].push_back(Edge(0,2));

    Graph[1].push_back(Edge(1,2));
    Graph[1].push_back(Edge(1,3));

    Graph[2].push_back(Edge(2,0));
    Graph[2].push_back(Edge(2,1));
    Graph[2].push_back(Edge(2,2));

    Graph[3].push_back(Edge(3,1));
    Graph[3].push_back(Edge(3,2));

    display(Graph, v);
    printNeighbour(Graph,2);

}